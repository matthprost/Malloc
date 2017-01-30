##
## Makefile for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
##
## Made by Matthias Prost
## Login   <prost_m@epitech.eu>
##
## Started on  Wed Jan 25 14:09:51 2017 Matthias Prost
## Last update Mon Jan 30 17:23:33 2017 Matthias Prost
##

all:
	@make --no-print-directory -C src

clean:
	@make clean --no-print-directory  -C src

fclean:
	@make fclean  --no-print-directory -C src

re:
	@make re  --no-print-directory -C src

lib:
	@make lib  --no-print-directory -C src
