#include <stdio.h>

int main(void)
{
  unsigned int x, y;
  int i;
  int Month[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char *Day[10] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  scanf("%d %d", &x, &y);

  if(1<=x && x<=12 && 1<=y && y<= 31)
  {
    for(i=0;i<x-1;i++)
      y += Month[i];

    printf("%s\n", Day[y%7]);
  }
  return 0;
}
