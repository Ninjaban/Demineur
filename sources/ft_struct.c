/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:03:21 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 11:41:37 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

static int	ft_init_char(char ***tab)
{
	size_t	n;

	if ((*tab = malloc(sizeof(char *) * WIDTH)) == NULL)
		return (ERROR);
	n = 0;
	while (n < WIDTH)
		if (((*tab)[n++] = malloc(sizeof(char) * LENGHT)) == NULL)
			return (ERROR);
	return (TRUE);
}

static void	ft_init_mine_pro(char ***mine, int x, int y)
{
	if (x < 0 || x >= LENGHT || y < 0 || y >= WIDTH)
		return ;
	if ((*mine)[y][x] != MINE)
		(*mine)[y][x]++;
}

static void	ft_init_mine(char ***mine)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
			(*mine)[y][x++] = 0;
		y = y + 1;
	}
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
		{
			(*mine)[y][x] = ((rand() % 100) < DENSITY) ? MINE : (*mine)[y][x];
			if ((*mine)[y][x] == MINE)
			{
				ft_init_mine_pro(&(*mine), x - 1, y);
				ft_init_mine_pro(&(*mine), x + 1, y);
				ft_init_mine_pro(&(*mine), x, y - 1);
				ft_init_mine_pro(&(*mine), x, y + 1);
				ft_init_mine_pro(&(*mine), x - 1, y - 1);
				ft_init_mine_pro(&(*mine), x + 1, y + 1);
				ft_init_mine_pro(&(*mine), x - 1, y + 1);
				ft_init_mine_pro(&(*mine), x + 1, y - 1);
			}
			x = x + 1;
		}
		y = y + 1;
	}
}

static void	ft_init_bool(char ***tab, char bool)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGHT)
			(*tab)[y][x++] = bool;
		y = y + 1;
	}
}

static void	ft_free_tab(char **tab)
{
	size_t	n;

	n = 0;
	if (tab)
	{
		while (n < WIDTH)
			free(tab[n++]);
		free(tab);
	}
}

void		ft_freemap(t_map *map)
{
	if (map)
	{
		ft_free_tab(map->hide);
		ft_free_tab(map->mine);
		ft_free_tab(map->flag);
		free(map);
	}
}

t_map		*ft_init(void)
{
	t_map	*map;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if (ft_init_char(&(map->mine)) == ERROR)
		return (NULL);
	if (ft_init_char(&(map->hide)) == ERROR)
		return (NULL);
	if (ft_init_char(&(map->flag)) == ERROR)
		return (NULL);
	srand(time(NULL));
	ft_init_mine(&(map->mine));
	ft_init_bool(&(map->hide), TRUE);
	ft_init_bool(&(map->flag), FALSE);
	return (map);
}
