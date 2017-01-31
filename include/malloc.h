/*
** malloc.h for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 14:18:39 2017 Matthias Prost
** Last update Tue Jan 31 16:51:15 2017 loic lopez
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
  bool	isFree;
  struct s_list	*next;
  struct s_list	*prev;
  void		*data;
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

#endif
