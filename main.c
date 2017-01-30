/*
** main.c for main in /home/prost_m/Rendu/Semestre_4/PSU_2016_malloc/
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Wed Jan 25 14:58:41 2017 Matthias Prost
** Last update Mon Jan 30 13:16:00 2017 Matthias Prost
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

struct header_t {
	size_t size;
	unsigned is_free;
	struct header_t *next;
};

struct header_t *head, *tail;

pthread_mutex_t global_malloc_lock;

struct header_t *get_free_block(size_t size)
{
	struct header_t *curr = head;
	while(curr) {
		if (curr->is_free && curr->size >= size)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void *malloc(size_t size)
{
	size_t total_size;
	void *block;
	struct header_t *header;
	if (!size)
		return NULL;
	pthread_mutex_lock(&global_malloc_lock);
	header = get_free_block(size);
	if (header) {
		header->is_free = 0;
		pthread_mutex_unlock(&global_malloc_lock);
		return (void*)(header + 1);
	}
	total_size = sizeof(struct header_t) + size;
	block = sbrk(total_size);
	if (block == (void*) -1) {
		pthread_mutex_unlock(&global_malloc_lock);
		return NULL;
	}
	header = block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	if (!head)
		head = header;
	if (tail)
		tail->next = header;
	tail = header;
	pthread_mutex_unlock(&global_malloc_lock);
	return (void*)(header + 1);
}

void	free(void *ptr)
{
  brk(ptr);
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
