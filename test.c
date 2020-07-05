#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_strn(char a, char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int main ()
{
    char s[] = "ef\ndrtgre\n";

	printf("%d", ft_strn('\n', s));
    return (0);
}
