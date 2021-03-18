/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:20:16 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 12:20:20 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		newdstsize;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	fs_dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	fs_dst_len = dst_len;
	src_len = ft_strlen(src);
	newdstsize = dstsize - dst_len - 1;
	if (newdstsize < 0)
		return (src_len + dstsize);
	while (newdstsize > 0 && src[i])
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
		newdstsize--;
	}
	dst[dst_len] = '\0';
	return (src_len + fs_dst_len);
}
