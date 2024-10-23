#include "lem_in.h"

void display_error(char *error_msg)
{
    ft_printf("ERROR\n");
    ft_printf("%s\n", error_msg);
    //CHECK FOR LEAKS
    exit(1);
}