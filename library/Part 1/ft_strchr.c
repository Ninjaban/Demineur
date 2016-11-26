/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:16 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/04 14:14:44 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		n;

	n = 0;
	while (s[n] && s[n] != c)
		n = n + 1;
	if (s[n] == c)
		return ((char *)(s + n));
	return (NULL);
}