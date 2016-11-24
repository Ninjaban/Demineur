/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:55:15 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 11:57:00 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

static int	ft_nbdigit(int nbr)
{
	int		nb;

	nb = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nb = nb + 1;
		nbr = nbr / 10;
	}
	return (nb);
}

static void	ft_putnbchar(char c, size_t nb)
{
	size_t	n;

	n = 0;
	while (++n <= nb)
		ft_putchar(c);
}

void		ft_display(t_map *map)
{
	size_t	x;
	size_t	y;

	ft_putnbchar(' ', ft_nbdigit(WIDTH) + 1);
	ft_putchar('+');
	ft_putnbchar('-', WIDTH);
	ft_putstr("+\n");
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		ft_putnbr(y);
		ft_putnbchar(' ', ft_nbdigit(WIDTH) - ft_nbdigit(y) + 1);
		ft_putchar('|');
		while (x < LENGHT)
		{
			if (map->flag[y][x] == TRUE)
				ft_putchar('O');
			else if (map->hide[y][x] == TRUE)
				ft_putchar('#');
			else if (map->mine[y][x] == MINE)
				ft_putchar('X');
			else
				ft_putchar(map->mine[y][x] + '0');
			x = x + 1;
		}
		ft_putstr("|\n");
		y = y + 1;
	}
	ft_putnbchar(' ', ft_nbdigit(WIDTH) + 1);
	ft_putchar('+');
	ft_putnbchar('-', WIDTH);
	ft_putstr("+\n");
}



















