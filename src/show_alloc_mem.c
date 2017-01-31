/*
** show_alloc_mem.c for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Tue Jan 31 11:05:54 2017 Matthias Prost
** Last update Tue Jan 31 11:33:37 2017 Matthias Prost
*/

#include "malloc.h"

void	show_alloc_mem()
{
  t_list	*list;

  list = first;
  while (list)
    {
      printf("%p", list->stock);
      list = list->next;
    }
}
