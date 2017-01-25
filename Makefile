##
## Makefile for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
##
## Made by Matthias Prost
## Login   <prost_m@epitech.eu>
##
## Started on  Wed Jan 25 14:09:51 2017 Matthias Prost
## Last update Wed Jan 25 14:09:51 2017 Matthias Prost
##


CFLAGS	=				-W -Wall -Werror -fpic
CFLAGS  +=      -I./include

CC	=	gcc

NAME    =	libmy_malloc.so

SRC	=	 malloc.c \

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[5;31m"
YELLOW  =	"\033[1;33m"
FINISH  =       "\033[5;1;35m"

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

clean:
		@rm -f $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
		@rm -f $(NAME) && \
		$(ECHO) $(GREEN) "[OK] rm" $(TEAL) $(NAME) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] rm" $(TEAL) $(NAME) $(DEFAULT)

re:	 fclean all

## Compilation -----------------------------------------------------------------

$(NAME):	$(OBJ)
		@$(CC) -shared -o $(NAME) $(OBJ) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $(OBJ) $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $(OBJ) $(DEFAULT)
		@$(ECHO) $(FINISH) "\nCompilation Succesfully of "$(NAME) $(DEFAULT)

%.o:		%.c
		@$(CC) -c $^ -o $@ $(CFLAGS) && \
		$(ECHO) $(GREEN) "[OK] gcc" $(TEAL) $^ $(DEFAULT) || \
		$(ECHO) $(RED) "[ERROR] gcc" $(TEAL) $^ $(DEFAULT)

.PHONY: 	all clean fclean re
