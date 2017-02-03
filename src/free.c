/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Fri Feb 03 14:47:51 2017 loic lopez
*/

#include "malloc.h"

t_list *get_list(void *ptr)
{
  char *tmp;

  tmp = ptr;
  return (ptr = tmp - (sizeof(t_list) - 8));
}

void	free(void *ptr)
{
  t_list	*current;

  pthread_mutex_lock(&global_lock);
  if (!ptr)
  {
    pthread_mutex_unlock(&global_lock);
    return;
  }
  current = get_list(ptr);
  if (current->isFree != 0)
    current->isFree = 1;
  if (current->next == NULL && ptr < sbrk(0))
    sbrk(0 - sizeof(t_list) - current->size);
  pthread_mutex_unlock(&global_lock);
}
