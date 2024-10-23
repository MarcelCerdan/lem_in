#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_room {
    int ant;
    char *name;
    struct s_room *link[];
} t_room;

int parse_arguments();
void display_error(char *error_msg);
char **get_map_from_file(char *argv);

#endif