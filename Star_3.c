#include <stdio.h>

/*

*****
****
***
**
*

*/

int main(void)
{
  unsigned int N;
  int i, j;
  scanf("%d", &N);

  if(1<=N && N<=100)
  {
    for(i=0;i<N;i++)
    {
      for(j=N-i;j>0;j--)
        printf("*");
      printf("\n");
    }
  }
  else
  {
    printf("옳바른 범위를 입력하세요\n");
    return -1;
  }
  return 0;
}
