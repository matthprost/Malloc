/*
** show_alloc_mem.c for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Tue Jan 31 11:05:54 2017 Matthias Prost
** Last update Wed Feb  1 18:59:26 2017 Matthias Prost
*/

#include "malloc.h"

int     my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb < 10)
    my_putchar(nb + '0');
  else if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
  else
    my_putstr("Entrée Invalide");
  return (0);
}

void	show_alloc_mem()
{
  t_list	*list;

  list = listHead;
  my_putstr("break : ");
  print_address(sbrk(0));
  my_putstr("\n");

  while (list)
    {
      print_address(list->stock);
      my_putstr(" - ");
      print_address(list->stock + list->size);
      my_putstr(" : ");
      my_put_nbr(list->size);
      my_putstr(" bytes\n");
      list = list->next;
    }
}
