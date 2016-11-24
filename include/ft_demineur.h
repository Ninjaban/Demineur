/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:36:05 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 11:51:25 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEMINEUR_H
# define FT_DEMINEUR_H

# define LENGHT 10
# define WIDTH 10
# define DENSITY 20

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define DEF -2
# define MINE -5

# define PROMPT "$> "
# define ERROR_T "Erreur de traitement."
# define USAGE "Commandes disponibles:\ndemin X Y\nCreuser sur la case pointer\
 par X/Y\ndrap X Y\nPose un drapeau sur la case X/Y"

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
/*
void		ft_freemap(t_bool **map);
void		ft_displaymap(t_bool **map);
t_bool		**ft_tabdup(t_bool **map);


int			ft_createmap(t_bool ***map);
int			ft_algo(t_cmd *cmd, t_bool ***map);
int			ft_demin(t_bool ***map, int x, int y, t_bool first);
*/
void		ft_freemap(t_map *map);
void		ft_display(t_map *map);
int			ft_algo(t_cmd *cmd, t_map **map);
int			ft_demin(t_map **map, int x, int y, char bool);
int			ft_parsing(t_cmd **cmd, char *line);
int			ft_demineur(void);
t_map		*ft_init(void);

#endif
