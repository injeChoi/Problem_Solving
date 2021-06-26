#include <stdio.h>

int main(void)
{
  unsigned int N;
  int i;
  scanf("%d", &N);

  if(1<=N && N<=9)
  {
    for(i=1;i<10;i++)
      printf("%d * %d = %d\n", N, i, N*i);
  }

  else
  {
    printf("옳바른 범위를 입력하세요\n");
    return -1;
  }

  return 0;
}
