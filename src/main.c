#include "malloc.h"

int main()
{
  char	*str;
  char	*str2;
  char	*str3;

  str = malloc(2);
  str2 = malloc(2);
  str3 = malloc(4);
  show_alloc_mem();
  realloc(str2, 5);
  realloc(str, 5);
  realloc(str3, 5);
  str3 = malloc(4);
  show_alloc_mem();
  return 0;
}
