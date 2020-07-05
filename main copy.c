

#include "get_next_line.h"

int main ()
{
    int fd;
    int ret;
    static char *line = NULL;
    fd = open("./NAME", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("\nresults %d -> %s \n", ret, line);
        free(line);
        line = NULL;
    }
    printf("RESULTAT -> %d -> %s \n", ret, line);
    system("leaks a.out");
    close(fd);
    return (0);
}