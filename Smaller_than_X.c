#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned int N, X;
  int i;
  int *A;
  scanf("%d %d", &N, &X);
  A = (int *)malloc(sizeof(int)*N);

  if(1<=N && N<=10000 && 1<=X && X<=10000)
  {
    for(i=0;i<N;i++)
      scanf("%d", &A[i]);
    for(i=0;i<N;i++)
    {
      if(A[i]<X)
        printf("%d ", A[i]);
    }
    printf("\n");
  }
  else
  {
    printf("옳바른 범위를 입력하세요\n");
    return -1;
  }
  free(A);
  return 0;
}
