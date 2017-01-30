##
## Makefile for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
##
## Made by Matthias Prost
## Login   <prost_m@epitech.eu>
##
## Started on  Wed Jan 25 14:09:51 2017 Matthias Prost
## Last update Mon Jan 30 17:12:23 2017 Matthias Prost
##


CFLAGS	=				-W -Wall -Werror -Wextra -fpic -I./include

CC	=	gcc

NAME    =	libmy_malloc.so
NAMES		= malloc

SOURCES = src

SRC	=	 $(SOURCES)/malloc.c \

SRCS = $(SOURCES)/main.c \

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(SOURCES)/$(OBJ) $(SOURCES)/$(OBJS) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(OBJS) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(OBJS) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) $(NAMES) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:	 fclean all

lib:
	gcc -c -Wall -Werror -fpic src/main.c -I./include
	gcc -shared -o libmy_malloc.so src/main.o -I./include

## Compilation -----------------------------------------------------------------

$(NAME):	$(OBJS)
		@$(CC) $(FLAGS) -o $(NAMES) $(OBJS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAMES) $(DEFAULT)

%.o:		%.c
		@$(CC) -c $^ -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all clean fclean re
