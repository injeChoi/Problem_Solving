#include <stdio.h>

int main(void)
{
  int a, b, c, cnt;
  unsigned int N;
  scanf("%d", &N);

  if(N<100)
    printf("%d\n", N);
  else
  {
    cnt = 99;
    for(int i=100;i<=N;i++)
    {
      a = i / 100; //백의 자리
      b = (i/10) % 10; // 십의 자리
      c = i % 10; // 일의 자리

      if(a-b == b-c)
        cnt++;
    }
    printf("%d\n", cnt);
  }

  return 0;
}
