#include <stdio.h>

void star(int N, int x, int y);
char arr[3072][6144];

int main(void)
{
  unsigned int N;
  int i, j;
  scanf("%d", &N);

  for(i=0;i<N;i++)      //배열 초기화 성공
  {
    for(j=0;j<2*N;j++)
    {
      if(j==2*N-1)
        arr[i][j] = ' ';
      else
        arr[i][j] = ' ';
    }
  }

  star(N, N-1, 0); // 최초 별의 좌표

  for(i=0;i<N;i++)      // 별 출력
  {
    for(j=0;j<2*N;j++)
    {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void star(int N, int x, int y)   // 재귀로 삼각형 나누기
{
  if(N==3) // 더 이상 삼각형이 쪼개질 수 없을 때 별 입력
  {
    arr[y][x] = '*';  // 1번째 줄 별
    arr[y+1][x-1] = '*';  // 2번째 줄 별
    arr[y+1][x+1] = '*';
    arr[y+2][x-2] = '*';  // 3번째 줄 별
    arr[y+2][x-1] = '*';
    arr[y+2][x] = '*';
    arr[y+2][x+1] = '*';
    arr[y+2][x+2] = '*';
    return;
  }
  // 최초 가장 큰 삼각형을 3분할 하여 위, 왼쪽, 오른쪽으로 나눈다.
  star(N/2, x, y);  //가장 위에 있는 삼각형의 기준 점
  star(N/2, x-(N/2), y+(N/2));  //완쪽에 있는 삼각형의 기준 점
  star(N/2, x+(N/2), y+(N/2));  //오른쪽에 있는 삼각형의 기준 점
}
