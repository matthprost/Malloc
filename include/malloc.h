/*
** malloc.h for malloc in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Mon Jan 30 14:18:39 2017 Matthias Prost
** Last update Mon Jan 30 15:42:39 2017 Matthias Prost
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_header
{
  size_t		size;
  bool		free;
  struct s_header	*next;
} t_header;

t_header *head, *end;

#endif
