/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:07:12 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/02 18:07:13 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*newstr;
	void				*ans;

	newstr = s;
	i = 0;
	ans = NULL;
	while (n)
	{
		if (newstr[i] == (unsigned char)c)
		{
			ans = (void*)&newstr[i];
			return (ans);
		}
		i++;
		n--;
	}
	return (ans);
}
