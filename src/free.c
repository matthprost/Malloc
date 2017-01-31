/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Tue Jan 31 18:18:16 2017 loic lopez
*/

#include "malloc.h"

#define SIZE_TO_MOVE 210

void	free(void *ptr)
{
  t_list	*tmp;

  if (!ptr)
    return;

  tmp = listHead;

  while (tmp != NULL)
    {

  //     if (tmp->data + SIZE_TO_MOVE == ptr)
	// write(1, "salut\n", 6);
      tmp = tmp->next;
    }
}
