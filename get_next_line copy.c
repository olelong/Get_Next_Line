/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olelong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:06:10 by olelong           #+#    #+#             */
/*   Updated: 2019/12/04 18:58:52 by olelong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** fonctions pour checker les lignes selon la taille du buffer
** et compter les lignes car si il en affiche une il retourne 1 et quand 
** il arrive au \0 il retourne (0)
*/
int		ft_count_line(char **line)
{
	int i;
	static char *stock;

	i = 0;
	if (!(stock = malloc(sizeof(BUFFER_SIZE + 1))))
		return (NULL);
	while (*line[i])
	{
		if (line[i] == '\n') 
			return (0);
		if (line[i] != '\n' && line[i] < BUFFER_SIZE)
		{
			stock = line;
			i++;
			return (1);
		}
		return (1);
		ft_free(stock);
	}
	return(0);
}

int		get_next_line(int fd, char **line)
{
	static char *stock;
	int i;
	int ret;

	ret = 0;
	i = 0;
	
	
	return (ret);
}


int		ft_calzero(char *line, size_t count)
{
	char static		*stock;
	size_t			i;

	i = 0;
	if (stock == line)
		ft_free(stock);
	while (line[i])
	{
		while (line[i] != '\n')
			i++;
		if (i > count)
			stock = line[i];
		return (1);
	}
	stock = NULL;
	if (line == '\0')
		return (0);
	return (0);
}

