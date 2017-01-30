/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Mon Jan 30 12:45:47 2017 Matthias Prost
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *malloc(size_t sz)
{
  void *mem;
  static unsigned char our_memory[1024 * 1024];
  static size_t next_index = 0;

  if(sizeof our_memory - next_index < sz)
        return NULL;

  next_index += sz;
  mem = sbrk(next_index);
  return mem;
}

void	free(void *ptr)
{
  brk(ptr);
}

int		main()
{
  char	*str;
  int		i;
  char	*buff;

  if ((str = malloc(sizeof(char) * 5)) == NULL)
    {
      printf("ERROR MALLOC\n");
      return 0;
    }
  buff = "Hello";
  i = -1;
  while (buff[++i])
    str[i] = buff[i];
  printf("%s\n", buff);
}
