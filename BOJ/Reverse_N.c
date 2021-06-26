#include <stdio.h>

int main(void)
{
  unsigned int N;
  int i;
  scanf("%d", &N);

  if(N<=100000)
  {
    for(i=N;i>0;--i)
      printf("%d\n", i);
  }

  else
  {
    printf("100000 이하의 수를 입력하세요\n");
    return -1;
  }

  return 0;
}
