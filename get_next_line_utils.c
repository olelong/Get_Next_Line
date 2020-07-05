/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olelong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:05:52 by olelong           #+#    #+#             */
/*   Updated: 2019/12/14 19:22:51 by olelong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_free(char ***ptr)
{
	free(**ptr);
	**ptr = NULL;
}

char		*ft_newstr(size_t i)
{
	char	*str;
	size_t	j;

	j = 0;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (str[j])
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

char		*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*sourc;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	i = 0;
	if (!n || sourc == dest)
		return (dest);
	while (n--)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
