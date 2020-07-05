/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olelong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:05:34 by olelong           #+#    #+#             */
/*   Updated: 2019/12/06 13:39:08 by olelong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int			ft_strn(char a, char *str);
int			get_next_line(int fd, char **line);
int			ft_intstr(char **line, char **stock);
size_t		ft_strlen(const char *s);

char		*ft_strjoin_free(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_newstr(size_t i);

void		ft_free(char ***ptr);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
