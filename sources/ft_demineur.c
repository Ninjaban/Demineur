/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 13:21:34 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

size_t			ft_getvalue(int lvl, int l, int w)
{
  if (lvl == 1)
    return ((l == TRUE) ? LENGHT_1 : (w == TRUE) ? WIDTH_1 : DENSITY_1);
  else if (lvl == 2)
    return ((l == TRUE) ? LENGHT_2 : (w == TRUE) ? WIDTH_2 : DENSITY_2);
  else if (lvl == 3)
    return ((l == TRUE) ? LENGHT_3 : (w == TRUE) ? WIDTH_3 : DENSITY_3);
  else
    return ((l == TRUE) ? LENGHT_4 : (w == TRUE) ? WIDTH_4 : DENSITY_4);
}

int			ft_demineur(int lvl)
{
	t_cmd	*cmd;
	t_map	*map;
	char	*line;

	cmd = NULL;
	if ((map = ft_init(lvl)) == NULL)
		return (ERROR);
	/* Code */
	ft_display(map, lvl);
	ft_putendl(USAGE);
	while (42)
	{
		ft_putstr(PROMPT);
		line = NULL;
		if (get_next_line(0, &line) == -1)
		{
		  ft_freemap(map, lvl);
		  return (ERROR);
		}
		if (ft_parsing(&cmd, line) != ERROR)
		{
		  if (ft_algo(cmd, &map, lvl) == TRUE)
			{
			  ft_freemap(map, lvl);
			  free(cmd);
			  return (TRUE);
			}
		}
		else
			ft_putendl(USAGE);
		if (line)
			free(line);
	}
	/* !Code */
	return (TRUE);
}
