#include <stdio.h>

int main(void)
{
  unsigned int Score;
  scanf("%d", &Score);

  if(0<=Score && Score<=100)
  {
    if(90<=Score)
      printf("A\n");
    else if(80<=Score)
      printf("B\n");
    else if(70<=Score)
      printf("C\n");
    else if(60<=Score)
      printf("D\n");
    else
      printf("F\n");
  }

  else
  {
    printf("옳바른 범위를 입력하세요 (0~100)\n");
    return -1;
  }

  return 0;
}
