/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:28:10 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/01 14:28:13 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == c)
			p = &s[i];
		i++;
	}
	if (p != 0)
		return ((char*)p);
	if (c == '\0')
		return ((char*)&s[i]);
	return (NULL);
}
