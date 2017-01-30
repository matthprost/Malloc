/*
** realloc.c for realloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:25:21 2017 Matthias Prost
** Last update Mon Jan 30 17:50:56 2017 Matthias Prost
*/

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
  void		*buff;
  t_list	*list;

  if (!ptr)
    return (malloc(size));
  list = (t_list *)ptr - 1;
  if (list->size >= size)
    return (ptr);
  buff = malloc(size);
  if (buff)
    {
      memcpy(buff, ptr, header->size);
      free(ptr);
    }
  return buff;
}
