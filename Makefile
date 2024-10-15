.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	lem_in

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRC		= 	srcs/

DIR_HEAD 	=	headers/

DIR_LIBFT	=	libft/

# ---- Files ---- #

LIBFT = $(DIR_LIBFT)/libft.a

HEAD_LIST	=	lem_in.h \

SRCS_LST 	= 	main.c \
				parsing/parse_arguments.c \

OBJS 		= 	$(addprefix $(DIR_OBJS), $(SRCS_LST:.c=.o))

DEPS		=	$(OBJS:.o=.d)


# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS = -L ${DIR_LIBFT}
IFLAGS = -I ${DIR_HEAD} -I ${DIR_LIBFT}

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
DFLAG	=	-MMD -MP

# ********* RULES ******** #

.PHONY:				all
all			:	${NAME}

-include		$(DEPS)

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${LIBFT}
					${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o $@

# ---- Compiled Rules ---- #

$(LIBFT):			
					$(MAKE) -C $(DIR_LIBFT)

$(DIR_OBJS)%.o	:	$(DIR_SRC)%.c $(DIR_LIBFT)
					${MKDIR} $(shell dirname $@)
					${CC} ${CFLAGS} ${DFLAG} ${IFLAGS} -c $< -o $@

# ---- Usual Commands ---- #

.PHONY:				clean
clean			:
					$(MAKE) clean -C ${DIR_LIBFT}
					${RM} ${DIR_OBJS}

.PHONY:				fclean
fclean			:	clean
					${RM} ${NAME}
					$(MAKE) fclean -C ${DIR_LIBFT}

.PHONY:				re
re				:	fclean
					$(MAKE) all