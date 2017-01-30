/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Mon Jan 30 15:47:24 2017 Matthias Prost
*/

#include "malloc.h"

t_header *get_block(size_t size)
{
  t_header *tmp;

  tmp = head;
  while (tmp)
    {
      if (!tmp->free && tmp->size >= size)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void	*malloc(size_t size)
{
  t_header	*header;
  size_t		total;
  void		*buff;

  if (size <= 0)
    return (NULL);
  if ((header = get_block(size)))
    {
      header->free = false;
      return (void *)(header + 1);
    }
  total = sizeof(t_header) + size;
  buff = sbrk(total);
  if (buff == (void *) -1)
    return (NULL);
  header = buff;
  header->size = size;
  header->free = false;
  header->next = NULL;
  if (!head)
    head = header;
  if (end)
    end->next = header;
	end = header;
  return ((void *)(header + 1));
}

void free(void *block)
{
	(void)block;
}

// int		main()
// {
//   char	*str;
//   int		i;
//   char	*buff;
//
//   if ((str = malloc(sizeof(char) * 5)) == NULL)
//     {
//       printf("ERROR MALLOC\n");
//       return 0;
//     }
//   buff = "Hello";
//   i = -1;
//   while (buff[++i])
//     str[i] = buff[i];
//   printf("%s\n", buff);
//   // my_free(str);
// }
