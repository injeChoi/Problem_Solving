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
  int i, j=0;
  scanf("%d", &N);

  if(1<=N && N<=100)
  {
    for(i=0;i<N;i++)
    {
      for(j=1;j<=i;j++)
        printf(" ");
      for(j=1;j<=N-i;j++)
        printf("*");
      printf("\n");
    }
  }
  else
  {
    printf("옳바른 값을 입력하세요\n");
    return -1;
  }
  return 0;
}
