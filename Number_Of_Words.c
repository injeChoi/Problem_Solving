#include <stdio.h>

int main(void)
{
  char arr[1000001];
  int i, word=1;
  scanf(" %[^\n]", arr);

  while(arr[i]!='\0')
  {
    if(arr[i]==' ' && arr[i+1]!='\0')
      word++;
    i++;
  }

  if(arr[0]==' ' || arr[0]=='\0')
    word--;

  printf("%d\n", word);
  return 0;
}
