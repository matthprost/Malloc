/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Thu Feb  2 18:34:32 2017 Matthias Prost
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

  if (!ptr)
    return;
  current = get_list(ptr);
  if (current->isFree != 0)
    current->isFree = 1;
}
