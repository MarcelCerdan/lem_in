#include "lem_in.h"

static int check_line_validity(char *line);
static int check_ant_nb(char *str_ant_nb);
static int check_room(argv);

int parse_arguments(char **argv)
{
    int i = 0;
    int ant_nb = -1;
    

    while (argv[i])
    {
        check_line_validity(argv[i]);
        if (ant_nb == -1)
            ant_nb = check_ant_nb(argv[i]);
        check_room();
    }
    return (0);
}

static int check_line_validity(char *line)
{
    if (line[0])
}

static int check_ant_nb(char *str_ant_nb)
{
    int ant_nb = ft_atoi(str_ant_nb);

    if (ant_nb <= 0)
        display_error("Invalid number of ants");

    return (ant_nb);
}

static int check_room(argv)
{
    
}