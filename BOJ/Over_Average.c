#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned int C, N;
  int *score = (int *)malloc(sizeof(int)*N);
  double *percentage = (double *)malloc(sizeof(double)*C);
  int sum=0, cnt=0;
  double average = 0.0;
  int i, j;

  scanf("%d", &C);

  for(i=0;i<C;i++)
  {
    scanf("%d", &N);
    if(1<=N && N<=1000)
    {
      for(j=0;j<N;j++)
      {
        scanf("%d", &score[j]);
        if(score[j]<0 || score[j]>100)
        {
          printf("옳바른 범위를 입력하세요\n");
          return -1;
        }
        else
          sum += score[j];
      }
      average = (double)sum/N;

      for(j=0;j<N;j++)
      {
        if(score[j]>average)
          cnt++;
      }
    }
    percentage[i] = (double)cnt*100/N;
    sum = 0;
    cnt = 0;
    average = 0.0;
  }

  for(i=0;i<C;i++)
  {
    printf("%.3f%%\n", percentage[i]);
  }

  free(score);
  free(percentage);
  return 0;
}
