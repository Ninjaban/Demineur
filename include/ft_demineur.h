/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:36:05 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 13:49:20 by jcarra           ###   ########.fr       */
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
# define MINE -2
# define HIDE -3
# define DISCOVER -4
# define EXPLO -5
# define FLAG -6

# define ERROR_T "Erreur de traitement."
# define USAGE "Commandes disponibles:\ndemin X Y\nCreuser sur la case pointer\
 par X/Y\ndrap X Y\nPose un drapeau sur la case X/Y"

# include <stdio.h>
# include <time.h>
# include "libft.h"

typedef char		t_bool;

typedef struct		s_cmd
{
	int				demin;
	size_t			x;
	size_t			y;
}					t_cmd;

void		ft_freemap(t_bool **map);
void		ft_displaymap(t_bool **map);
int			ft_parsing(t_cmd **cmd, char *line);
int			ft_demineur(void);
int			ft_createmap(t_bool ***map);
int			ft_algo(t_cmd *cmd, t_bool ***map);

#endif
