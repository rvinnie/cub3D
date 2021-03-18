/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:28:44 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/05 09:28:47 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	ptr = NULL;
	len1 = ft_strlen(s1);
	if (!(ptr = (char*)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[len1] = s2[i];
		i++;
		len1++;
	}
	ptr[len1] = '\0';
	return (ptr);
}
