#include <stdio.h>

int main(void)
{
  int i, asc=0, des=0, mix=0;
  int arr[8];

  for(i=0;i<8;i++)
  {
    scanf("%d", &arr[i]);

    if(i+1 == arr[i])
      asc++;

    else if(8-i == arr[i])
      des++;

    else
      mix++;
  }

  if(asc == 8)
    printf("ascending\n");

  else if(des == 8)
    printf("descending\n");

  else
    printf("mixed\n");

  return 0;
}
