/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 20:01:32 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

int			ft_demineur(void)
{
	t_cmd	*cmd;
	t_bool	**map;
	char	*line;

	cmd = NULL;
	if (ft_createmap(&map) == ERROR)
		return (ERROR);
	/* Code */
	ft_displaymap(map);
	while (42)
	{
		ft_putstr(PROMPT);
		if (get_next_line(0, &line) == -1)
		{
			ft_freemap(map);
			return (ERROR);
		}
		if (ft_parsing(&cmd, line) != ERROR)
		{
			if (ft_algo(cmd, &map) == TRUE)
			{
				ft_freemap(map);
				free(cmd);
				return (TRUE);
			}
		}
		else
			ft_putendl(USAGE);
	}
	/* !Code */
	return (TRUE);
}
