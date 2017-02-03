##
## Makefile for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
##
## Made by Matthias Prost
## Login   <prost_m@epitech.eu>
##
## Started on  Wed Jan 25 14:09:51 2017 Matthias Prost
## Last update Thu Feb  2 18:21:03 2017 Matthias Prost
##


CC      =       gcc

NAME    =       ../libmy_malloc.so

ECHO    =       /bin/echo -e \

DEFAULT =       "\033[00m"
GREEN   =       "\033[0;32m"
TEAL    =       "\033[1;36m"
RED     =       "\033[5;31m"

CFLAGS  +=      -Wextra -Wall -Werror -fPIC -lpthread
CFLAGS  +=      -I../include/
CFLAGS  +=      -D_DEFAULT_SOURCE -D_XOPEN_SOURCE

SRC	=	free.c \
	malloc.c \
	realloc.c \
	show_alloc_mem.c \
	print_address.c \
	lib.c


OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -c $(CFLAGS) $(SRC)
	@$(CC) -shared -o $(NAME) $(OBJ) && \
	$(ECHO) $(GREEN) "[OK]" $(NAME) $(TEAL) $(OBJ) $(DEFAULT) && \
	$(ECHO) $(GREEN) "[OK] created shared library:" $(NAME) $(DEFAULT)

clean:
	@rm -f $(OBJ) && \
	$(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(OBJ) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OBJ) $(DEFAULT)

fclean:		clean
	@rm -f $(NAME) && \
  $(ECHO) $(GREEN) "[OK] remove" $(TEAL) $(NAME) $(DEFAULT) || \
  $(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $(OBJ) $(DEFAULT)

re: fclean all

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $^ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] doesn't exist" $(TEAL) $^ $(DEFAULT)


.PHONY: 	all clean fclean re
