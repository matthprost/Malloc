/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Wed Feb  1 19:12:53 2017 Matthias Prost
*/

#include "malloc.h"

#define SIZE_TO_MOVE 210

void	free(void *ptr)
{
  t_list	*tmp;

  if (!ptr)
    return;
  tmp = listHead;
  while (tmp->next)
    {
      if (tmp + SIZE_TO_MOVE == ptr)
	     {
	  //write(1, "salut\n", 6);
        return;
	     }
      tmp = tmp->next;
    }
//    brk(tmp->data);
}
