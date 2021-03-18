/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:46:59 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/05 15:47:02 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*strcreate(char *ptr, long int num, int len)
{
	int	x;

	x = 0;
	if (num < 0)
	{
		num *= -1;
		ptr[0] = '-';
		x++;
	}
	ptr[len] = '\0';
	len--;
	while (len >= x)
	{
		ptr[len] = num % 10 + 48;
		num /= 10;
		len--;
	}
	return (ptr);
}

char		*ft_itoa(int n)
{
	long int	num;
	int			len;
	char		*ptr;

	ptr = NULL;
	num = n;
	len = nbrlen(n);
	if (num <= 0)
		len++;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (num == 0)
	{
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	return (strcreate(ptr, num, len));
}
