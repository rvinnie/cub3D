/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:27:54 by rvinnie           #+#    #+#             */
/*   Updated: 2020/11/01 17:27:56 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_putnbr(const char *str, int minus)
{
	unsigned int	i;
	unsigned long	ans;

	i = 0;
	ans = 0;
	while (ft_isdigit(str[i]))
	{
		ans = ans * 10 + (str[i] - 48);
		i++;
	}
	if (minus == 1)
		ans *= -1;
	return (ans);
}

static	int		ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int				ft_atoi(const char *str)
{
	long long int	i;
	int				minus;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
	{
		minus = 0;
		i++;
	}
	else if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	return (ft_putnbr(&str[i], minus));
}
