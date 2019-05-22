#include <stdio.h>

int main(void)
{
  unsigned int n;
  int i, sum=0;
  scanf("%d", &n);

  if(1<=n && n<=10000)
  {
    for(i=1;i<=n;i++)
      sum += i;
    printf("%d\n", sum);
  }

  return 0;
}
