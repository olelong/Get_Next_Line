#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;
    char *line = NULL;

    fd = open(argv[argc-1], O_RDONLY);
    while (get_next_line(fd, &line))
    {
       ft_putendl(line);
    }
    system("leaks a.out");
    close(fd);
    return (0);
}
