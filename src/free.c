/*
** free.c for free in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 17:30:08 2017 Matthias Prost
** Last update Wed Feb  1 19:25:55 2017 Matthias Prost
*/

#include "malloc.h"

void	free(void *ptr)
{
  t_list	*tmp;

  if (!ptr)
    return;
  tmp = listHead;
  while (tmp->next)
    {
      my_putstr("break: ");
      print_address(tmp->stock);
      my_putstr("\n");
      print_address((void *)tmp);
      my_putstr("-");
      print_address(ptr);
      my_putstr("\n");
      if ((void *)tmp == ptr)
	     {
	  write(1, "Done!\n", 6);
        return;
	     }
      tmp = tmp->next;
    }
    my_putstr("break: ");
    print_address(tmp->stock);
    my_putstr("\n");
    print_address((void *)tmp);
    my_putstr("-");
    print_address(ptr);
    my_putstr("\n");
//    brk(tmp->data);
}
