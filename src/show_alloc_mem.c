/*
** show_alloc_mem.c for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/src/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Tue Jan 31 11:05:54 2017 Matthias Prost
** Last update Fri Feb 03 13:24:22 2017 loic lopez
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
  my_putstr("0x");
  my_putnbr_base_size((size_t)sbrk(0), "0123456789ABCDEF");
  my_putstr("\n");
  while (list)
    {
      my_putstr("0x");
      my_putnbr_base_size((size_t)list, "0123456789ABCDEF");
      my_putstr(" - ");
      my_putstr("0x");
      my_putnbr_base_size((size_t)list + sizeof(t_list) + list->size
      , "0123456789ABCDEF");
      my_putstr(" : ");
      my_put_nbr(list->size + sizeof(t_list));
      my_putstr(" bytes\n");
      list = list->next;
    }
}
