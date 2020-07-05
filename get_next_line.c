/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olelong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:06:10 by olelong           #+#    #+#             */
/*   Updated: 2019/12/07 17:40:14 by olelong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** fonctions comme strrchr pour chercher le /n
*/

int		ft_strn(char a, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

/*
** on doit faire lorsque on lit une ligne return 1 ou fin de fichier 0
*/

int		ft_intstr(char **line, char **stock)
{
	char	*str;
	int		i;

	i = ft_strn('\n', *stock);
	if (i != -1)
	{
		*line = ft_newstr(i + 1);
		ft_memcpy(*line, *stock, i);
		(*line)[i] = '\0';
		str = ft_strdup(*stock + i + 1);
		ft_free(&stock);
		*stock = str;
		return (1);
	}
	*line = ft_strdup(*stock);
	ft_free(&stock);
	return (0);
}

/*
** Permet de concatener ce que contient la variable stock et de free
*/

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (dest);
}

/*
** on gere les possibles erreurs
** puis on stock et concatene, free et on va jusqu a la fin du fichier
** ouvert.
** if (!stock)
** ft_newstr(0);
*/

int		get_next_line(int fd, char **line)
{
	static char		*stock = NULL;
	int				ret;
	char			buf[BUFFER_SIZE + 1];

	if (!line)
		return (-1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!stock)
		stock = ft_newstr(0);
	while (ft_strn('\n', stock) == -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(stock = ft_strjoin_free(stock, buf)))
			return (-1);
	}
	return (ft_intstr(line, &stock));
}
