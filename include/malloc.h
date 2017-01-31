/*
** malloc.h for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 14:18:39 2017 Matthias Prost
** Last update Tue Jan 31 11:27:04 2017 Matthias Prost
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_list
{
  size_t		size;
  bool		free;
  void		*stock;
  struct s_list	*next;
} t_list;

t_list *first, *last;

void	*malloc(size_t size);

void	*realloc(void *ptr, size_t size);

void	free(void *ptr);

void	show_alloc_mem();

#endif
