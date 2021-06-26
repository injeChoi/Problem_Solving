#include <stdio.h>

int main(void)
{
  unsigned int N;
  unsigned int score[1001];
  double MAX = 0.0;
  double sum = 0.0;
  scanf("%d", &N);

  for(int i=0;i<N;i++)
    scanf("%d", &score[i]);

  for(int i=0;i<N;i++)
  {
    if(score[i]>MAX)
      MAX = (double)score[i];
  }

  for(int i=0;i<N;i++)
    sum += score[i]/MAX * 100;

  printf("%.2f\n", sum/(double)N);

  return 0;
}
