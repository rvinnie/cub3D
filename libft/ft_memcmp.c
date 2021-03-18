/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:24:21 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 18:24:23 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*newstr1;
	const unsigned char	*newstr2;

	newstr1 = s1;
	newstr2 = s2;
	i = 0;
	while (i < n)
	{
		if (newstr1[i] != newstr2[i])
			return (newstr1[i] - newstr2[i]);
		i++;
	}
	return (0);
}
