#include <stdio.h>

int main(void)
{
  unsigned int A, B, C;
  int sum=0, i;
  int arr[11]={0,};

  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);

  sum = A*B*C;

  while(sum>0)
  {
    arr[sum%10]++;
    sum = sum/10;
  }

  for(i=0;i<10;i++)
    printf("%d\n", arr[i]);

  return 0;
}
