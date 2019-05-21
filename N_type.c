#include <stdio.h>

int main(void)
{
  unsigned int N;
  int i;
  scanf("%d", &N);

  if(N<=100000)
  {
    for(i=0;i<N;i++)
      printf("%d\n", i+1);
  }

  else
  {
    printf("100000 이하의 수를 입력하세요\n");
    return -1;
  }

  return 0;
}
