#include <stdio.h>

int main()
{
  int i, num;

  printf("몇까지 출력할까요?: ");
  scanf("%d", &num);

  if(num<=100000)
  {
    for(i=0;i<num;i++)
      printf("%d\n", i+1);
  }

  else
  {
    printf("100000 이하의 수를 입력하세요\n");
    return -1;
  }

  return 0;
}
