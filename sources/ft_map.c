/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:00:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 13:49:15 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

void		ft_freemap(t_bool **map)
{
	size_t	n;

	n = 0;
	if (map)
	{
		while (n < WIDTH)
			free(map[n++]);
		free(map);
	}
}

void		ft_displaymap(t_bool **map)
{
	size_t	n;
	size_t	i;

	n = 0;
	while (n < WIDTH)
	{
		i = 0;
		while (i < LENGHT)
		{
			if (map[n][i] == MINE)
				ft_putchar('#');
			else if (map[n][i] == EXPLO)
				ft_putchar('X');
			else if (map[n][i] == DISCOVER)
				ft_putchar(' ');
			else if (map[n][i] == HIDE)
				ft_putchar('#');
			else if (map[n][i] == FLAG)
				ft_putchar('O');
			else
				ft_putchar(map[n][i] + '0');
			i = i + 1;
		}
		ft_putchar('\n');
		n = n + 1;
	}
}

static void	ft_completemap(t_bool ***map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
			(*map)[y][x++] = ((rand() % 100) < DENSITY) ? MINE : HIDE;
		y = y + 1;
	}
}

int			ft_createmap(t_bool ***map)
{
	size_t	n;

	if (!map)
		return (ERROR);
	if ((*map = malloc(sizeof(t_bool *) * WIDTH)) == NULL)
		return (ERROR);
	n = 0;
	while (n < WIDTH)
		(*map)[n++] = NULL;
	n = 0;
	while (n < WIDTH)
		if (((*map)[n++] = malloc(sizeof(t_bool) * LENGHT)) == NULL)
		{
			ft_freemap(*map);
			return (ERROR);
		}
	srand(time(NULL));
	ft_completemap(&(*map));
	return (TRUE);
}
