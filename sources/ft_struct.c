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

static int	ft_init_char(char ***tab, int lvl)
{
	size_t	n;

	if ((*tab = malloc(sizeof(char *) * ft_getvalue(lvl, FALSE, TRUE))) == NULL)
		return (ERROR);
	n = 0;
	while (n < ft_getvalue(lvl, FALSE, TRUE))
		if (((*tab)[n++] = malloc(sizeof(char) * ft_getvalue(lvl, TRUE, FALSE))) == NULL)
			return (ERROR);
	return (TRUE);
}

static void	ft_init_mine_pro(char ***mine, int x, int y, int lvl)
{
  if (x < 0 || x >= (int)ft_getvalue(lvl, TRUE, FALSE) || y < 0 || y >= (int)ft_getvalue(lvl, FALSE, TRUE))
		return ;
	if ((*mine)[y][x] != MINE)
		(*mine)[y][x]++;
}

static void	ft_init_mine(char ***mine, int lvl)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < ft_getvalue(lvl, FALSE, TRUE))
	{
		x = 0;
		while (x < ft_getvalue(lvl, TRUE, FALSE))
			(*mine)[y][x++] = 0;
		y = y + 1;
	}
	y = 0;
	while (y < ft_getvalue(lvl, FALSE, TRUE))
	{
		x = 0;
		while (x < ft_getvalue(lvl, TRUE, FALSE))
		{
		  (*mine)[y][x] = ((rand() % 100) < (int)ft_getvalue(lvl, FALSE, FALSE)) ? MINE : (*mine)[y][x];
			if ((*mine)[y][x] == MINE)
			{
			  ft_init_mine_pro(&(*mine), x - 1, y, lvl);
			  ft_init_mine_pro(&(*mine), x + 1, y, lvl);
			  ft_init_mine_pro(&(*mine), x, y - 1, lvl);
			  ft_init_mine_pro(&(*mine), x, y + 1, lvl);
			  ft_init_mine_pro(&(*mine), x - 1, y - 1, lvl);
			  ft_init_mine_pro(&(*mine), x + 1, y + 1, lvl);
			  ft_init_mine_pro(&(*mine), x - 1, y + 1, lvl);
			  ft_init_mine_pro(&(*mine), x + 1, y - 1, lvl);
			}
			x = x + 1;
		}
		y = y + 1;
	}
}

static void	ft_init_bool(char ***tab, char bool, int lvl)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < ft_getvalue(lvl, FALSE, TRUE))
	{
		x = 0;
		while (x < ft_getvalue(lvl, TRUE, FALSE))
			(*tab)[y][x++] = bool;
		y = y + 1;
	}
}

static void	ft_free_tab(char **tab, int lvl)
{
	size_t	n;

	n = 0;
	if (tab)
	{
		while (n < ft_getvalue(lvl, FALSE, TRUE))
			free(tab[n++]);
		free(tab);
	}
}

void		ft_freemap(t_map *map, int lvl)
{
	if (map)
	{
	  ft_free_tab(map->hide, lvl);
	  ft_free_tab(map->mine, lvl);
	  ft_free_tab(map->flag, lvl);
	  free(map);
	}
}

t_map		*ft_init(int lvl)
{
	t_map	*map;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if (ft_init_char(&(map->mine), lvl) == ERROR)
		return (NULL);
	if (ft_init_char(&(map->hide), lvl) == ERROR)
		return (NULL);
	if (ft_init_char(&(map->flag), lvl) == ERROR)
		return (NULL);
	srand(time(NULL));
	ft_init_mine(&(map->mine), lvl);
	ft_init_bool(&(map->hide), TRUE, lvl);
	ft_init_bool(&(map->flag), FALSE, lvl);
	return (map);
}
