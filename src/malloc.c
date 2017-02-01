/*
** main.c for main in /home/prost_m/Rlastu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Wed Feb 01 15:26:02 2017 loic lopez
*/

#include "malloc.h"

void	*malloc(size_t size)
{
  t_list	*new_link;

  new_link = sbrk(0);
  new_link = sbrk(sizeof(t_list));
  if(new_link == (void *)-1 || size <= 0)
    return (NULL);
  new_link->size = size;
  new_link->next = NULL;
  new_link->prev = NULL;
  new_link->isFree = false;
  new_link->data = sbrk(size);
  if (new_link->data == (void *)-1)
    return (NULL);
  if (!listHead)
    {
      listHead = new_link;
      list = new_link;
    }
  else
    {
      list->next = new_link;
      new_link->prev = list;
      list = new_link;
    }
  return (new_link->data);
}
