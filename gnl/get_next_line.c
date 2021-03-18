/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:43:32 by rvinnie           #+#    #+#             */
/*   Updated: 2020/12/11 10:43:36 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cleaner(char *tmp, int ret)
{
	if (tmp)
		free(tmp);
	return (ret);
}

int		fill_remainder(char **remainder, char *buf)
{
	char *ptr_n;

	ptr_n = NULL;
	if ((ptr_n = ft_strchr(buf, '\n')))
	{
		*ptr_n = '\0';
		++ptr_n;
		free(*remainder);
		if (!(*remainder = ft_strdup(ptr_n)))
			return (-1);
		return (1);
	}
	return (0);
}

int		check_remainder(char **remainder, char **line)
{
	char	*ptr_to_n;
	char	*tmp;

	tmp = *remainder;
	if ((ptr_to_n = ft_strchr(*remainder, '\n')))
	{
		if (ft_strlen(ptr_to_n) == ft_strlen(*remainder))
		{
			if (!(*line = ft_strdup("\0"))
				|| !(*remainder = ft_strdup(++ptr_to_n)))
				return (cleaner(tmp, -1));
			return (cleaner(tmp, 1));
		}
		*ptr_to_n = '\0';
		if (!(*line = ft_strdup(*remainder)))
			return (cleaner(tmp, -1));
		if (*++ptr_to_n == '\0')
			return (ft_str_clr(*remainder, 2));
		if (!(*remainder = ft_strdup(ptr_to_n)))
			return (cleaner(tmp, -1));
		return (cleaner(tmp, 1));
	}
	if (!(*line = ft_strdup(*remainder)))
		return (cleaner(tmp, -1));
	return (ft_str_clr(*remainder, 0));
}

int		read_and_join(int fd, char **remainder, char **line)
{
	char	*buf;
	char	*ptr_n;
	int		count_byte;
	int		flag;

	flag = 0;
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!flag && (count_byte = read(fd, buf, BUFFER_SIZE)))
	{
		if (count_byte == -1)
		{
			free(*line);
			*line = NULL;
			return (cleaner(buf, -1));
		}
		buf[count_byte] = '\0';
		if ((flag = fill_remainder(remainder, buf)) == -1)
			return (cleaner(buf, -1));
		ptr_n = ft_strjoin(*line, buf);
		free(*line);
		*line = ptr_n;
	}
	return (cleaner(buf, count_byte));
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder = NULL;
	int			flag;
	int			count_byte;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (cleaner(remainder, -1));
	flag = 0;
	count_byte = 0;
	if (remainder)
		flag = check_remainder(&remainder, line);
	else
	{
		if (!(*line = ft_strdup("\0")))
			return (cleaner(remainder, -1));
	}
	if (flag == 0)
		count_byte = read_and_join(fd, &remainder, line);
	if (count_byte == -1 || flag == -1)
		return (cleaner(remainder, -1));
	if (count_byte || ft_strlen(remainder) || flag > 0)
		return (1);
	free(remainder);
	remainder = NULL;
	return (0);
}
