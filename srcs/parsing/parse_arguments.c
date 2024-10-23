#include "lem_in.h"

static int check_start_end(char *line, t_room **start, t_room **end);
static int check_ant_nb(char *str_ant_nb);
static char *skip_comment(char *line);
static t_room *check_line(char *line, t_room *room);
static t_room *fill_start_end(t_room *room_to_fill);
static size_t param_len(char *line);

int parse_arguments()
{
    int ant_nb = -1;
	t_room *start = NULL;
	t_room *end = NULL;
    char *line = get_next_line(0);

    while (line)
    {
		line = skip_comment(line);
		if (!line)
			return (0);
		if (ant_nb == -1)
			ant_nb = check_ant_nb(line);
		check_start_end(line, &start, &end);
		line = get_next_line(0);
    }
	free(line);
    return (0);
}

static char *skip_comment(char *line)
{
	if (line[0] == '#' && ft_strcmp(line, "##start\n") != 0 && ft_strcmp(line, "##end\n") != 0)
		return (get_next_line(0));
	return (line);
}

static int check_ant_nb(char *str_ant_nb)
{
	if (ft_strlen(str_ant_nb) != param_len(str_ant_nb))
		display_error("Invalid number of ants.");

    int ant_nb = ft_atoi(str_ant_nb);

    if (ant_nb <= 0)
        display_error("Invalid number of ants.");
    return (ant_nb);
}

static int check_start_end(char *line, t_room **start, t_room **end)
{
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start\n") == 0)
		{
			if (*start != NULL)
				display_error("Multiple start commands");
			*start = fill_start_end(*start);
		}
		else if ((ft_strcmp(line, "##end\n") == 0))
		{
			if (*end != NULL)
				display_error("Multiple end commands");
			*end = fill_start_end(*end);
		}
	}
	return (0);
}

static size_t param_len(char *line)
{
	int i = 0;

	while (line[i] != '\0' && line[i] != ' ')
		i++;
	return (i);
}

static int get_coord(char *line, int begin, int param_size) {
	char param[param_size + 1];

	ft_strncpy(param, line + begin, param_size);
	param[param_size + 1] = '\0';

	int param_int = ft_atoi(param);
	if (param_int < 0)
		display_error("Wrong coordinates");
	
	return (param_int);
}

static t_room *fill_start_end(t_room *room_to_fill)
{
	char *line = get_next_line(0);

	if (!line)
		display_error("Wrong start or end.");

	return (check_line(line, room_to_fill));
}

static t_room *check_line(char *line, t_room *room)
{
	room = malloc(sizeof(t_room));

	if (line[0] == 'L')
		display_error("Room name can't start with \'L\'");

	size_t size = param_len(line);

	room->name = malloc((sizeof(char) * size) + 1);
	if (!room->name)
		display_error("Malloc error");
	
	ft_strncpy(room->name, line, size);
	room->name[size + 1] = '\0';

	size_t first_param_len = param_len(line + size + 1);
	size_t second_param_len = param_len(line + first_param_len + 1);

	int coord_x = get_coord(line, size + 1, first_param_len);
	int coord_y = get_coord(line, size + first_param_len + 1, second_param_len);

	(void) coord_x;
	(void) coord_y;

	return (room);

}