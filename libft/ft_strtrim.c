/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:45:50 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/05 09:45:51 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	find_start(char const *s1, char const *set, size_t len)
{
	long int	start;

	start = 0;
	while (start < (long int)len)
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	return (start);
}

static long int	find_end(char const *s1, char const *set, int end)
{
	while (end >= 0)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	if (end < 0)
		return (0);
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	size_t		len;
	char		*ptr;

	if (!s1 || !set)
		return (NULL);
	ptr = NULL;
	len = ft_strlen(s1);
	start = find_start(s1, set, len);
	end = find_end(s1, set, len - 1);
	if (start >= end)
		len = 0;
	else
		len = end + 1 - start;
	if (!(ptr = (char*)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	len = 0;
	while (start <= end)
		ptr[len++] = s1[start++];
	ptr[len] = '\0';
	return (ptr);
}
