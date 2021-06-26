#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned int T;
  int *A;
  int *B;
  int i;
  scanf("%d", &T);

  A = (int *)malloc(sizeof(int)*T);
  B = (int *)malloc(sizeof(int)*T);

  if(1<=T && T<=1000000)
  {
    for(i=0;i<T;i++)
      scanf("%d %d", &A[i], &B[i]);
    for(i=0;i<T;i++)
      printf("%d\n", A[i]+B[i]);
  }

  free(A);
  free(B);
  return 0;
}
