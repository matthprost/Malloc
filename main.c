/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Wed Jan 25 15:08:19 2017 Matthias Prost
*/

#include <stdlib.h>

int		main()
{
  char	*str;
  int		i;
  char	*buff;

  str = malloc(sizeof(char) * 5);
  buff = "Hello";
  i = -1;
  while (buff[++i])
    str[i] = buff[i];
}
