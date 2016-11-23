/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 13:48:03 by jcarra           ###   ########.fr       */
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
	while (42)
	{
		if (get_next_line(0, &line) == -1)
		{
			ft_freemap(map);
			return (ERROR);
		}
		if (ft_parsing(&cmd, line) != ERROR)
		{
			if (ft_algo(cmd, &map) == TRUE)
				return (TRUE);
		}
		else
			ft_putendl(USAGE);
	}
	/* !Code */
	ft_freemap(map);
	return (TRUE);
}
