/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:36:11 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 16:36:12 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = dst;
	newsrc = (unsigned char *)src;
	if (newdst == NULL && newsrc == NULL)
		return (dst);
	while (n--)
		*newdst++ = *newsrc++;
	return (dst);
}
