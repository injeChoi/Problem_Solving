#include <stdio.h>
#include <string.h>

int main(void)
{
  unsigned int n;
  int cnt=1, sum=0, i, j;
  char arr[81];
  scanf("%d", &n);

  for(i=0;i<n;i++)
  {
    scanf("%s", arr);

    for(j=0;j<strlen(arr);j++)
    {
      if(arr[j] == 'O')
      {
        sum += cnt;
        cnt++;
      }

      if(arr[j] == 'X')
        cnt=1;
    }
    printf("%d\n", sum);
    sum = 0;
    cnt = 1;
  }

  return 0;
}
