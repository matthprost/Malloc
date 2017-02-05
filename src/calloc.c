/*
** calloc.c for PSU_2016_malloc in /Users/loiclopez/Documents/Shared/Epitech/year_2016/PSU_2016_malloc/src
**
** Made by loic lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  Sun Feb 05 17:07:33 2017 loic lopez
** Last update Sun Feb 05 17:11:52 2017 loic lopez
*/

#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
	size_t	finalSize;
	void	*memory;

	if (!nmemb || !size)
		return (NULL);
	finalSize = nmemb * size;
	if (size != finalSize / nmemb)
	 return (NULL);
	if (!(memory = malloc(finalSize)))
		return (NULL);
	memset(memory, 0, finalSize);
	return (memory);
}
