#include <stdio.h>

int main(void)
{
  unsigned int A, B, C;
  int Biggest=0;
  int Second=0;
  scanf("%d %d %d", &A, &B, &C);

  if(1<=A && A<=100 && 1<=B && B<=100 && 1<=C && C<=100)
  {
    Biggest = A >= B ? A : B;
    Biggest = Biggest >= C ? Biggest : C;

    if(A == Biggest)
      Second = B >= C ? B : C;
    if(B == Biggest)
      Second = A >= C ? A : C;
    if(C == Biggest)
      Second = A >= B ? A : B;

    printf("%d\n", Second);
  }
  else
  {
    printf("옳바른 A,B,C 범위를 입력하세요 (1~100)\n");
    return -1;
  }
  
  return 0;
}
