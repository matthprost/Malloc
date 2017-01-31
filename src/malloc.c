/*
** main.c for main in /home/prost_m/Rlastu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Tue Jan 31 12:00:48 2017 Matthias Prost
*/

#include "malloc.h"

void	*malloc(size_t size)
{
  t_list	*list;
  void		*buff;

  if (size <= 0)
    return (NULL);
  buff = sbrk(sizeof(t_list));
  if (buff == (void *) -1)
    return (NULL);
  list = buff;
  list->stock = sbrk(size);
  list->size = size;
  list->free = false;
  list->next = NULL;
  if (!first)
    first = list;
  if (last)
    last->next = list;
	last = list;
  return (list->stock);
}
