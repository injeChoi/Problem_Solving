#include <stdio.h>

int main(void)
{
  int i,j,k,t,a[3];
  unsigned int N;
  int han = 0;
  scanf("%d", &N);

  for(i=1;i<=N;i++)
  {
    if(i<100)
      han = i;

    else if(i == 1000)
      break;

    else
    {
      k=0; t=1;
      while(t>0)
      {
        a[k] = t % 10;
        t /= 10;
        k++;
      }
      if(a[0] - a[1] == a[1] - a[2])
        han++;
    }
  }
  printf("%d\n", han);

  return 0;
}
