/*
** main.c for main in /home/prost_m/Rlastu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Wed Feb  1 19:00:13 2017 Matthias Prost
*/

#include "malloc.h"

void	*malloc(size_t size)
{
  t_list	*new_link;
  void		*buff;
  size_t	memory;

  buff= sbrk(0);
  memory = sizeof(t_list) + size;
  new_link = sbrk(memory);
  if(new_link == (void *)-1 || size <= 0)
    return (NULL);
  new_link->stock = buff;
  new_link->size = size;
  new_link->next = NULL;
  new_link->isFree = false;
  if (!listHead)
    {
      listHead = new_link;
      list = new_link;
    }
  else
    {
      list->next = new_link;
      list = new_link;
    }
  return ((void *)(new_link + 1));
}
