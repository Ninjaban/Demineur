/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:46:22 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 12:18:36 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

static void	ft_demin_rec(t_map **map, int x, int y, char bool)
{
	ft_demin(&(*map), x - 1, y, bool);
	ft_demin(&(*map), x + 1, y, bool);
	ft_demin(&(*map), x, y - 1, bool);
	ft_demin(&(*map), x, y + 1, bool);
	ft_demin(&(*map), x - 1, y - 1, bool);
	ft_demin(&(*map), x + 1, y + 1, bool);
	ft_demin(&(*map), x + 1, y - 1, bool);
	ft_demin(&(*map), x - 1, y + 1, bool);
}

int			ft_demin(t_map **map, int x, int y, char bool)
{
	if (x < 0 || x >= LENGHT || y < 0 || y >= WIDTH)
		return ((bool == TRUE) ? ERROR : FALSE);
	if ((*map)->flag[y][x] == TRUE)
	{
		ft_putendl("Un drapeau se trouve sur cette case.");
		return (FALSE);
	}
	if ((*map)->mine[y][x] == MINE)
	{
		(*map)->hide[y][x] = (bool == TRUE) ? FALSE : (*map)->hide[y][x];
		return ((bool == TRUE) ? DEF : FALSE);
	}
	if ((*map)->hide[y][x] == FALSE)
		return (FALSE);
	if ((*map)->hide[y][x] == TRUE)
		(*map)->hide[y][x] = (bool >= FALSE) ? FALSE : TRUE;
	if (bool >= FALSE)
		ft_demin_rec(&(*map), x, y, ((*map)->mine[y][x] == 0) ? FALSE : FALSE - 1);
	return (TRUE);
}

static int	ft_discover_mine(t_map **map, int x, int y)
{
	char	bool;

	bool = TRUE;
	if (x - 1 >= 0)
		bool = ((*map)->hide[y][x - 1] == FALSE || (*map)->mine[y][x - 1] == MINE) ? bool : FALSE;
	if (x + 1 < LENGHT)
		bool = ((*map)->hide[y][x + 1] == FALSE || (*map)->mine[y][x + 1] == MINE) ? bool : FALSE;
	if (y - 1 >= 0)
		bool = ((*map)->hide[y - 1][x] == FALSE || (*map)->mine[y - 1][x] == MINE) ? bool : FALSE;
	if (y + 1 < WIDTH)
		bool = ((*map)->hide[y + 1][x] == FALSE || (*map)->mine[y + 1][x] == MINE) ? bool : FALSE;
	if (x - 1 >= 0 && y - 1 >= 0)
		bool = ((*map)->hide[y - 1][x - 1] == FALSE || (*map)->mine[y - 1][x - 1] == MINE) ? bool : FALSE;
	if (x + 1 < LENGHT && y - 1 >= 0)
		bool = ((*map)->hide[y - 1][x + 1] == FALSE || (*map)->mine[y - 1][x + 1] == MINE) ? bool : FALSE;
	if (y + 1 < WIDTH && x - 1 >= 0)
		bool = ((*map)->hide[y + 1][x - 1] == FALSE || (*map)->mine[y + 1][x - 1] == MINE) ? bool : FALSE;
	if (y + 1 < WIDTH && x + 1 < LENGHT)
		bool = ((*map)->hide[y + 1][x + 1] == FALSE || (*map)->mine[y + 1][x + 1] == MINE) ? bool : FALSE;
	return (bool);
}

static int	ft_discover(t_map **map)
{
	size_t	x;
	size_t	y;
	char	bool;

	y = 0;
	bool = TRUE;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
			if ((*map)->mine[y][x++] == MINE)
			{
				if (ft_discover_mine(&(*map), x - 1, y) == FALSE)
					bool = FALSE;
				else
					(*map)->hide[y][x - 1] = FALSE;
			}
		y = y + 1;
	}
	return (bool);
}

static int	ft_end(char bool)
{
	if (bool == TRUE)
	{
		ft_putendl("Vous avez gagnée!");
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_algo_demin(t_cmd *cmd, t_map **map)
{
	int		ret;

	ret = ft_demin(&(*map), cmd->x, cmd->y, TRUE);
	if (ret == DEF)
	{
		ft_display(*map);
		ft_putendl("Vous avez perdu!");
		return (TRUE);
	}
	if (ret == ERROR)
	{
		ft_display(*map);
		ft_putendl("Cette position n'existe pas!");
		return (FALSE);
	}
	if (ret == TRUE)
		if ((ret = ft_discover(&(*map))) == FALSE)
		{
			ft_display(*map);
			return (FALSE);
		}
	ft_display(*map);
	return (ft_end(ret));
}

static void	ft_algo_drap(t_cmd *cmd, t_map **map)
{
	if (cmd->y < WIDTH && cmd->x < LENGHT)
		(*map)->flag[cmd->y][cmd->x] = ((*map)->flag[cmd->y][cmd->x] == FALSE) ? TRUE : FALSE;
	else
		ft_putendl("Cette position n'existe pas!");
}

int			ft_algo(t_cmd *cmd, t_map **map)
{
	if (cmd->demin == TRUE)
		return (ft_algo_demin(cmd, &(*map)));
	else
		ft_algo_drap(cmd, &(*map));
	ft_display(*map);
	return (FALSE);
}
