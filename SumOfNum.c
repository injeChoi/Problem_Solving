#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned int n;
  char *num_n = (char *)malloc(sizeof(char)*n);
  int i, sum=0;

  scanf("%d", &n);
  scanf("%s", &num_n[i]);

  for(i=0;i<n;i++)
    sum += num_n[i]-'0';

  printf("%d\n", sum);
  
  return 0;
}
