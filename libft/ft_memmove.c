/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:46:39 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 17:46:41 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*newdst;
	unsigned const char	*newsrc;

	newdst = dst;
	newsrc = src;
	if (newdst == newsrc)
		return (dst);
	else if (dst > src)
	{
		newdst += len;
		newsrc += len;
		while (len--)
			*(--newdst) = *(--newsrc);
	}
	else
	{
		while (len--)
			*(newdst++) = *(newsrc++);
	}
	return (dst);
}
