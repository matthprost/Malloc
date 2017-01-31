##
## Makefile for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
##
## Made by Matthias Prost
## Login   <prost_m@epitech.eu>
##
## Started on  Wed Jan 25 14:09:51 2017 Matthias Prost
## Last update Tue Jan 31 16:34:14 2017 lopez_i
##


CFLAGS	=	-W -Wall -Werror -Wextra -fPIC -I../include

CC	=	gcc

NAME    =	libmy_malloc.so
NAMES	=	malloc


SRCS =	malloc.c \
	realloc.c \
	free.c \
	show_alloc_mem.c \
	lib.c	\
	print_address.c	\
	main.c


ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"


OBJS = $(SRCS:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJS) $(DEFAULT)

fclean:		clean
		@rm -f ../$(NAME) $(NAMES) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:	 fclean all

lib:
	gcc -c $(CFLAGS) $(SRCS)
	gcc -shared -o ../libmy_malloc.so $(OBJS) $(CFLAGS)

## Compilation -----------------------------------------------------------------

$(NAME):	$(OBJS)
		@$(CC) $(FLAGS) -o $(NAMES) $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJS) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAMES) $(DEFAULT)

%.o:		%.c
		@$(CC) -c $^ -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all clean fclean re
