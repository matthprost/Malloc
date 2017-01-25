/*
** malloc.c for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc
**
** Made by Matthias Prost
** Login   <prost_m@epitech.net>
**
** Started on  Wed Jan 25 11:06:11 2017 Matthias Prost
** Last update Wed Jan 25 15:08:04 2017 Matthias Prost
*/

#include <unistd.h>
#include <stdlib.h>

void	*my_malloc(unsigned int size)
{
  return (malloc(size));
}
