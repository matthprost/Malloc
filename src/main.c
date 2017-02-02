#include "malloc.h"

int main()
{
  char	*str;
  char	*str2;
  char	*str3;
  int	i;

  i = 0;
  str = malloc(2);
  for (i = 0; i < 2; i++)
    {
      str[i] = 'i';
    }
  free(str);
  str2 = malloc(2);
  for ( i = 0; i < 2; i++)
    {
      str2[i] = 'i';
    }
  str3 = malloc(4);
  for ( i = 0; i < 3; i++)
    {
      str3[i] = 'i';
    }
  free(str2);
  free(str3);
  return 0;
}
