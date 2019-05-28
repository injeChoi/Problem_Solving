#include <stdio.h>

int main(void)
{
  unsigned int N;
  int A, B, C, add=0;
  int count = 0;
  scanf("%d", &N);
  add = N;
  
  while(add != N || count == 0)
  {
    A = add / 10;
    B = add % 10;
    C = (A + B) % 10;
    A = B; B = C;
    add = A*10 + B;
    count++;
  }
  printf("%d\n", count);

  return 0;
}
