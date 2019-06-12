#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[101];
  int arr[26];
  int i;
  scanf("%s", str);

  for(i=0;i<26;i++)
    arr[i] = -1;

  for(i=0;i<strlen(str);i++)
  {
    if(arr[str[i]-97] == -1) // a의 아스키코드 값이 97이고 b,c..는 98,99..이다
      arr[str[i]-97] = i;    /*str[i] 안에 a가 들어있고 97을 빼면 arr[0]이 된다.
                                arr[0]는 a의 위치를 알려주는 공간이다.
                                그 공간 안에 i의 값을 넣어주면 결국 arr[0] 는
                                a의 위치를 알려주는 수를 포함하게 된다.
                                같은 원리로 str[i]가 b를 갖고 있는 공간이었다면
                                arr[str[i]-97] == arr[98-97] 이 되고
                                b의 위치를 포함 해야 할 arr[1]의 공간에 또 i값을
                                넣어주면 최종적으로 arr[1]의 공간은 b의 위치를 알려주는
                                숫자를 갖고있게 된다.
                                */

  }

  for(i=0;i<26;i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
