#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "bool.h"

typedef struct s_room {
    struct s_room *link[];
    int ant;
    char name[];
} t_room;

int main(int ac, char **av);

#endif