# include "lem_in.h"

char **get_map_from_file(char *file_name) {
	int file = open(file_name, O_RDONLY);

	if (file < 0)
		display_error("Can't open file.");
	
	return NULL;
}