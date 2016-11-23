/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:28:37 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 13:05:02 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

static int	ft_init(t_cmd **cmd, char *line)
{
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (ERROR);
	if (!tab[0] || !tab[1] || !tab[2])
		return (ERROR);
	(*cmd)->demin = (ft_strncmp(tab[0], "demin", 4) == 0) ? MINE : FALSE;
	if (((*cmd)->demin == FALSE) && (ft_strncmp(tab[0], "drap", 3) != 0))
		return (ERROR);
	(*cmd)->x = ft_atoi(tab[1]);
	(*cmd)->y = ft_atoi(tab[2]);
	return (TRUE);
}

int			ft_parsing(t_cmd **cmd, char *line)
{
	if (!cmd)
		return (ERROR);
	if (*cmd)
		free(*cmd);
	if ((*cmd = malloc(sizeof(t_cmd))) == NULL)
		return (ERROR);
	if (ft_init(&(*cmd), line) == ERROR)
	{
		free(*cmd);
		return (ERROR);
	}
	return (TRUE);
}
