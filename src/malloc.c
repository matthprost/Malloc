/*
** main.c for main in /home/prost_m/Rlastu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Fri Feb 10 14:07:23 2017 Loic Lopez
*/

#include "malloc.h"

void		split(t_list *current, size_t size)
{
  t_list	*new;

  new = current->data + size;
  new->size = current->size - size;
  new->next = current->next;
  new->isFree = 1;
  current->size = size;
  current = new;
}

t_list		*verif_list(size_t size)
{
  t_list	*tmp;

  tmp = g_listHead;
  while (tmp)
    {
      if (tmp->size >= size && tmp->isFree == 1)
        return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		initlink(t_list *new_link, size_t size)
{
  new_link->data = new_link->str;
  new_link->size = size;
  new_link->next = NULL;
  new_link->prev = NULL;
  new_link->isFree = 0;
  if (!g_listHead)
    {
      g_listHead = new_link;
      g_list = new_link;
    }
  else
    {
      g_list->next = new_link;
      new_link->prev = g_list;
      g_list = new_link;
    }
}

void	*malloc(size_t size)
{
  t_list	*new_link;

  pthread_mutex_lock(&g_global_lock);
  new_link = verif_list(size);
  if (new_link)
    {
      split(new_link, size);
      new_link->isFree = 0;
    }
  else
    {
      if((new_link = sbrk(0)) == (void *)-1 || size <= 0)
	{
	  pthread_mutex_unlock(&g_global_lock);
	  return (NULL);
	}
      if (sbrk(sizeof(t_list) + size) == (void *)-1)
	{
	  pthread_mutex_unlock(&g_global_lock);
	  return (NULL);
	}
      initlink(new_link, size);
    }
  pthread_mutex_unlock(&g_global_lock);
  return (new_link->data);
}
