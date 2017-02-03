/*
** main.c for main in /home/prost_m/Rlastu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Fri Feb 03 14:43:56 2017 loic lopez
*/

#include "malloc.h"

t_list	*verif_block(size_t size)
{
  t_list	*tmp;

  tmp = listHead;
  while (tmp)
    {
      if (tmp->size >= size && tmp->isFree == 1)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void	initlink(t_list *new_link, size_t size)
{
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
  new_link->data = new_link->str;
  new_link->size = size;
  new_link->next = NULL;
  new_link->isFree = 0;
}

void	*malloc(size_t size)
{
  t_list	*new_link;

  // if ((new_link = verif_block(size)) != NULL)
  //     return (new_link->data);
  pthread_mutex_lock(&global_lock);
  new_link = sbrk(0);
  if(new_link == (void *)-1 || size <= 0)
    {
      pthread_mutex_unlock(&global_lock);
      return (NULL);
    }
  if ((sbrk(sizeof(t_list) + size)) == (void *)-1)
    {
      pthread_mutex_unlock(&global_lock);
      return (NULL);
    }
  initlink(new_link, size);
  pthread_mutex_unlock(&global_lock);
  return (new_link->data);
}
