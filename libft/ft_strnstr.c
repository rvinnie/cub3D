/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:53:44 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/13 13:00:50 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && len > i)
	{
		n = 0;
		if (haystack[i] == needle[n])
		{
			while ((i + n < len) && (haystack[i + n] == needle[n]))
			{
				n++;
				if (!needle[n])
					return ((char*)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
