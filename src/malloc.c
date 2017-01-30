/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Mon Jan 30 17:28:02 2017 Matthias Prost
*/

#include "malloc.h"

t_list *get_block(size_t size)
{
  t_list *tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->free && tmp->size >= size)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void	*malloc(size_t size)
{
  t_list	*list;
  size_t		total;
  void		*buff;

  if (size <= 0)
    return (NULL);
  if ((list = get_block(size)))
    {
      list->free = false;
      return (void *)(list + 1);
    }
  total = sizeof(t_list) + size;
  buff = sbrk(total);
  if (buff == (void *) -1)
    return (NULL);
  list = buff;
  list->size = size;
  list->free = false;
  list->next = NULL;
  if (!head)
    head = list;
  if (end)
    end->next = list;
	end = list;
  return ((void *)(list + 1));
}
