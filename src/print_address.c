/*
** print_address.c for PSU_2016_malloc in /Users/loiclopez/Documents/Shared/Epitech/year_2016/PSU_2016_malloc/src
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Tue Jan 31 16:18:13 2017 loic lopez
** Last update Tue Feb  7 14:50:57 2017 Matthias Prost
*/

#include "malloc.h"

int		my_putnbr_base_size(size_t nbr, char *base)
{
  size_t        start;
  size_t        taille;
  size_t        mod;
  
  taille = my_strlen(base);
  mod = nbr % taille;
  start = (nbr - mod) / taille;
  if (start != 0)
    my_putnbr_base_size(start, base);
  return (my_putchar(base[mod]));
}
