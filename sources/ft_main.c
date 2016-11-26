/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:35:43 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/23 18:54:47 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_demineur.h"

int			main()
{
  char	*str;
  int	nb;

  while (42)
    {
      ft_putstr("Choisissez un niveau entre 1 et 4 inclus.\n-> ");
      if (get_next_line(0, &str) == -1)
	return (1);
      if (ft_strncmp(str, "exit", 3) == 0)
	return (0);
      nb = ft_atoi(str);
      if (nb > 0 && nb < 5)
	if (ft_demineur(nb) == ERROR)
	  {
	    ft_putendl_fd(ERROR_T, 2);
	    return (1);
	  }
    }
  return (0);
}
