/*
** my_putstr.c for PSU_2016_malloc in /Users/loiclopez/Documents/Shared/Epitech/year_2016/PSU_2016_malloc/src
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Tue Jan 31 16:20:08 2017 loic lopez
** Last update Tue Jan 31 16:22:48 2017 loic lopez
*/

#include "malloc.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int     my_putstr(char *str)
{
  int c;

  c = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c = c + 1;
    }
  return (0);
}
