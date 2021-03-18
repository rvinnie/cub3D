/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:43:19 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 10:43:20 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen((const char *)dst);
	i = 0;
	if (!dstsize)
		return (src_len);
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (src_len);
}
