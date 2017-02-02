/*
** malloc.h for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 14:18:39 2017 Matthias Prost
** Last update Thu Feb  2 18:23:08 2017 Matthias Prost
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_list
{
  size_t		size;
  int		isFree;
  struct s_list	*next;
  void		*data;
  char	str[1];
}	t_list;

t_list	*listHead;
t_list	*list;

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);
void	show_alloc_mem();
void	print_address(void *ptr);
int	my_putstr(char *str);
int	my_putchar(char c);
int	my_strlen(char *str);
int my_put_nbr(int nb);
t_list *get_list(void *ptr);

#endif
