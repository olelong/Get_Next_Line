int     main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     ret;
    if (argc == 1)
        fd = 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (2);
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        printf("%d: %s\n", ret, line);
        free(line);
    }
    printf("%d: %s\n", ret, line);
    free(line);
    system("leaks a.out");
    if (argc == 2)
        close(fd);
}
