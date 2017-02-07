/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Tue Feb  7 14:20:10 2017 Matthias Prost
*/

#include "malloc.h"

t_list		*fusion(t_list *current)
{
  if (current->next && current->next->isFree)
    {
      current->size += sizeof(t_list) + current->next->size;
      current->next = current->next->next;
      if (current->next)
        current->next->prev = current;
    }
  return (current);
}

t_list		*get_list(void *ptr)
{
  char *tmp;
  
  tmp = ptr;
  return (ptr = tmp - (sizeof(t_list) - 8));
}

void		free(void *ptr)
{
  t_list	*current;

  pthread_mutex_lock(&global_lock);
  if (!ptr)
  {
    pthread_mutex_unlock(&global_lock);
    return;
  }
  current = get_list(ptr);
  current->isFree = 1;
  if(current->prev && current->prev->isFree)
    current = fusion(current->prev);
  if (current->next && current->next->isFree)
    current = fusion(current);
  pthread_mutex_unlock(&global_lock);
}
