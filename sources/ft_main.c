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
	if (LENGHT > 1 && WIDTH > 1 && (DENSITY > 0 && DENSITY < 100))
	{
		if (ft_demineur() == ERROR)
			ft_putendl_fd(ERROR_T, 2);
	}
	else
		ft_putendl_fd(ERROR_T, 2);
	return (0);
}
