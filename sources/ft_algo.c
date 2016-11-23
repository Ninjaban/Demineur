/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:46:22 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 13:48:46 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

static int	ft_end(t_bool **map, int ret)
{
	ft_displaymap(map);
	if (ret == TRUE)
		ft_putendl("Vous avez gagnee!");
	else
		ft_putendl("Vous avez perdu!");
	return (TRUE);
}

static int	ft_demin(t_bool ***map, size_t x, size_t y, t_bool first)
{
	int		ret;

	if (y >= WIDTH || y < 0 || x >= LENGHT || x < 0)
		return (FALSE);
	if (((*map)[y][x] == MINE  || (*map)[y][x] == EXPLO) && first == TRUE)
	{
		(*map)[y][x] = EXPLO;
		return (ERROR);
	}
	else if ((*map)[y][x] == MINE || (*map)[y][x] == EXPLO)
		return (TRUE);
	if ((*map)[y][x] == FALSE)
		(*map)[y][x] = DISCOVER;
	ret = 0;
	ret = ret + ft_demin(&(*map), x + 1, y, FALSE);
	ret = ret + ft_demin(&(*map), x - 1, y, FALSE);
	ret = ret + ft_demin(&(*map), x, y + 1, FALSE);
	ret = ret + ft_demin(&(*map), x, y - 1, FALSE);
	ret = ret + ft_demin(&(*map), x - 1, y + 1, FALSE);
	ret = ret + ft_demin(&(*map), x + 1, y + 1, FALSE);
	ret = ret + ft_demin(&(*map), x - 1, y - 1, FALSE);
	ret = ret + ft_demin(&(*map), x + 1, y - 1, FALSE);
	(*map)[y][x] = ret;
	return (FALSE);
}

static int	ft_discover(t_bool **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
			if (map[y][x++] == HIDE)
				return (FALSE);
		y = y + 1;
	}
	return (TRUE);
}

static int	ft_algo_demin(t_cmd *cmd, t_bool ***map)
{
	int		ret;

	ret = ft_demin(&(*map), cmd->x, cmd->y, TRUE);
	if (ret == FALSE)
		if ((ret = ft_discover(*map)) == FALSE)
			return (FALSE);
	return (ft_end(*map, ret));
}

static void	ft_algo_drap(t_cmd *cmd, t_bool ***map)
{
	(*map)[cmd->y][cmd->x] = ((*map)[cmd->y][cmd->x] - FLAG == MINE ||
							  (*map)[cmd->y][cmd->x] - FLAG == FALSE) ?
		(*map)[cmd->y][cmd->x] - FLAG : (*map)[cmd->y][cmd->x] + FLAG;
}

int			ft_algo(t_cmd *cmd, t_bool ***map)
{
	if (cmd->demin == TRUE)
		return (ft_algo_demin(cmd, &(*map)));
	else
		ft_algo_drap(cmd, &(*map));
	ft_displaymap(map);
	return (FALSE);
}
