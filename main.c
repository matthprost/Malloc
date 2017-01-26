/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Thu Jan 26 15:20:15 2017 Matthias Prost
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		*my_malloc(size_t size)
{
  if (brk(sbrk(size)) == -1)
    {
      printf("Done!");
      return (NULL);
    }
  else
    return (sbrk(size));
  return (NULL);
}

int		main()
{
  char	*str;
  char	*temp;
  int		i;
  char	*buff;

  if ((str = my_malloc(sizeof(char) * 5)) == NULL)
    {
      printf("ERROR MALLOC\n");
      return 0;
    }
  if ((temp = my_malloc(sizeof(char) * 5)) == NULL)
    {
      printf("ERROR MALLOC\n");
      return 0;
    }
  buff = "Hello";
  i = -1;
  while (buff[++i])
    {
      str[i] = buff[i];
      str[i] = temp[i];
    }
  printf("%s\n%s\n", buff, temp);
}
