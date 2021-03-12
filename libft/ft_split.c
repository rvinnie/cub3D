/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:08:31 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/05 17:08:33 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitstrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		**clear_memory(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

static char		*ft_splitstrdup(const char *s1, char c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_splitstrlen(s1, c) + 1))))
		return (NULL);
	while (s1[i] && s1[i] != c)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int		find_strs_count(char const *s, char c)
{
	long int	i;
	long int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			len++;
		}
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**ans;
	int		strs_count;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strs_count = find_strs_count(s, c);
	ans = NULL;
	if (!(ans = (char**)(malloc(sizeof(char*) * (strs_count + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (strs_count--)
	{
		while (s[j] && s[j] == c)
			j++;
		if (!(ans[i] = ft_splitstrdup(&s[j], c)))
			return (clear_memory(ans, i - 1));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ans[i] = NULL;
	return (ans);
}
