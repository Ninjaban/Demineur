/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:36:05 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 12:14:22 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEMINEUR_H
# define FT_DEMINEUR_H

/* # define LENGHT 10 */
/* # define WIDTH 10 */
/* # define DENSITY 25 */

# define LENGHT_1 5
# define WIDTH_1 5
# define DENSITY_1 25

# define LENGHT_2 7
# define WIDTH_2 7
# define DENSITY_2 30

# define LENGHT_3 10
# define WIDTH_3 10
# define DENSITY_3 35

# define LENGHT_4 25
# define WIDTH_4 25
# define DENSITY_4 40

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define DEF -2
# define MINE -5

# define PROMPT "$> "
# define ERROR_T "Erreur de traitement."
# define USAGE "Commandes disponibles:\nC X Y\nCreuser sur la case pointer\
 par X/Y\nD X Y\nPose un drapeau sur la case X/Y"

# include <stdio.h>
# include <time.h>
# include "libft.h"

typedef struct		s_cmd
{
	int				demin;
	size_t			x;
	size_t			y;
}					t_cmd;

typedef struct		s_map
{
	char			**mine;
	char			**hide;
	char			**flag;
}					t_map;

void		ft_freemap(t_map *map, int lvl);
void		ft_display(t_map *map, int lvl);
int			ft_algo(t_cmd *cmd, t_map **map, int lvl);
int			ft_demin(t_map **map, int x, int y, char bool, int lvl);
int			ft_parsing(t_cmd **cmd, char *line);
int			ft_demineur(int lvl);
size_t		ft_getvalue(int lvl, int l, int w);
t_map		*ft_init(int lvl);

#endif
