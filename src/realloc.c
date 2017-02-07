/*
** realloc.c for realloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:25:21 2017 Matthias Prost
** Last update Tue Feb  7 14:21:28 2017 Matthias Prost
*/

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  void		*buff;
  t_list	*list;

  if (!ptr)
    return (malloc(size));
  list = get_list(ptr);
  if (list->size >= size)
    return (ptr);
  buff = malloc(size);
  if (buff)
    {
      memcpy(buff, ptr, list->size);
      free(ptr);
    }
  return (buff);
}
