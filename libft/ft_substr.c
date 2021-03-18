/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:34:06 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/04 14:34:07 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = NULL;
	i = 0;
	if (!s || start < 0 || len < 0)
		return (NULL);
	len = ft_min(ft_strlen(s) - start, len);
	if (!(ptr = (char *)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	if (start >= ft_strlen(s))
		return (ptr);
	while (len > 0)
	{
		ptr[i] = s[start];
		start++;
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
