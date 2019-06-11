#include <stdio.h>

int main(void)
{
  int score[5];
  int sum=0, average=0;

  for(int i=0;i<5;i++)
  {
    scanf("%d", &score[i]);

    if(score[i] < 40)
      score[i] = 40;

    sum += score[i];
  }

  average = sum/5;

  printf("%d\n", average);

  return 0;
}
