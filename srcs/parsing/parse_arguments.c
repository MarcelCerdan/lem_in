#include "lem_in.h"

static int check_start_end(char *line, t_start_end *start_end);
static int check_ant_nb(char *str_ant_nb);
static int check_room(argv);
static int skip_comments(char **argv, int i);

int parse_arguments(char **argv)
{
    int i = 0;
    int ant_nb = -1;
	t_room *start = NULL;
	t_room *end = NULL;

    while (argv[i])
    {
		i = skip_comments(argv, i);
		if (ant_nb == -1)
			ant_nb = check_ant_nb(argv[i]);
		if (!check_start_end(argv[i]))
		{
			check_line(argv[i], start, end);
		}
    }
    return (0);
}

static int skip_comments(char **argv, int i)
{
	while (argv[i][0] == '#' && ft_strcmp(argv[i], "##start") != 0 && ft_strcmp(argv[i], "##end") != 0)
		i++;
	return (i);
}

static int check_ant_nb(char *str_ant_nb)
{
    int ant_nb = ft_atoi(str_ant_nb);

    if (ant_nb <= 0)
        display_error("Invalid number of ants");
    return (ant_nb);
}

static int check_start_end(char **argv, int i, t_room *start, t_room *end)
{
	char *line = argv[i];

	if (line == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			if (start != NULL)
				display_error("Multiple start commands");
			return (1);
		}
		else if ((ft_strcmp(line, "##end") == 0))
		{
			if (start_end->end != NULL)
				display_error("Multiple end commands");
			return (2);
		}
	}
	return (0);
}

static int param_len(char *line)
{
	int i = 0;

	while (line[i] != ' ')
		i++;
	return (i);
}

static void fill_start_end(char *line, t_room *room_to_fill)
{
	check_line()
}

static void check_line(char *line, t_room *room)
{
	if (line[0] == 'L')
		display_error("Room name can't start with \'L\'");

	int size = param_len(line);
	char room->name = malloc((sizeof(char) * size) + 1);

	if (!room->name)
		display_error("Malloc error");
	
	ft_strncpy(room->name, line, size);
	room->name[size + 1] = '\0';

	int first_param_len = param_len(line + size + 1);
	int second_param_len = param_len(line + first_param_len + 1);

	char first_param[first_param-len + 1];
	char second_param[second_param_len + 1];
}