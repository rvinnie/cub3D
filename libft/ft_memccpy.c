/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:57:36 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 16:57:38 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*newdst;
	unsigned const char	*newsrc;

	i = 0;
	newdst = dst;
	newsrc = src;
	while (i < n)
	{
		if (newsrc[i] == (unsigned char)c)
		{
			newdst[i] = newsrc[i];
			return (&newdst[i + 1]);
		}
		newdst[i] = newsrc[i];
		i++;
	}
	return (NULL);
}
