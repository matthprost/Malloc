#include "malloc.h"

int main()
{
  char	*str;
  char	*str2;
  char	*str3;

  str = malloc(2);
  str2 = malloc(2);
  str3 = malloc(4);
  free(str2);
  free(str3);
  free(str);
  show_alloc_mem();
  //realloc(str2, 5);
  return 0;
}
