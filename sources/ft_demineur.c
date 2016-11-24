/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_demineur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 11:42:42 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

int			ft_demineur(void)
{
	t_cmd	*cmd;
	t_map	*map;
	char	*line;

	cmd = NULL;
	if ((map = ft_init()) == NULL)
		return (ERROR);
	/* Code */
	ft_display(map);
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
