/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:28:37 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/24 11:52:00 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

void		ft_free_tab(char **tab)
{
	int		n;

	n = 0;
	if (tab)
	{
		while (tab[n])
			free(tab[n++]);
		free(tab);
	}
}

static int	ft_init_cmd(t_cmd **cmd, char *line)
{
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		return (ERROR);
	if (!tab[0] || !tab[1] || !tab[2])
		return (ERROR);
	(*cmd)->demin = (ft_strncmp(tab[0], "C", 0) == 0) ? TRUE : FALSE;
	if (((*cmd)->demin == FALSE) && (ft_strncmp(tab[0], "D", 0) != 0))
		return (ERROR);
	(*cmd)->x = ft_atoi(tab[1]);
	(*cmd)->y = ft_atoi(tab[2]);
	ft_free_tab(tab);
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
	if (ft_init_cmd(&(*cmd), line) == ERROR)
	{
		free(*cmd);
		return (ERROR);
	}
	return (TRUE);
}
