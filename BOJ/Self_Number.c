#include <stdio.h>
#include <stdbool.h>

bool arr[10002];
int NSN(int n);

int main(void)
{
  unsigned int N;
  int idx, i;

  for(i=1;i<=10000;i++)
  {
    idx = NSN(i);

    if(idx <= N)
      arr[idx] = true;
  }

  for(i=1;i<=10000;i++)
  {
    if(!arr[i])
      printf("%d\n", i);
  }

  return 0;
}

int NSN(int n)
{
  int sum = n;

  while(1)
  {
    if(n==0)
      break;
    sum += n%10;
    n = n/10;
  }

  return sum;
}
