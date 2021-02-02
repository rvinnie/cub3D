/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:44:07 by rvinnie           #+#    #+#             */
/*   Updated: 2020/12/11 10:44:09 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		check_remainder(char **remainder, char **line);
int		read_and_join(int fd, char **remainder, char **line);
int		fill_remainder(char **remainder, char *buf, char *ptr_n);
int		cleaner(char *tmp, int ret);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int		ft_str_clr(char *str, int ret);
size_t	ft_strcpy(char *dst, const char *src);
#endif
