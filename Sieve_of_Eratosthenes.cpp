#include <iostream>
#include <math.h>

// 에라토스테네스의 체
#define SIZE 100
int arr[SIZE+1];

int main(int argc, const char *argv[])
{
  int i,j;

  // 배열 초기화
  for(i=2;i<=SIZE;i++){
    arr[i] = i;
  }

  for (i=2;i<=sqrt(SIZE);i++){
    // 이미 체크된 수의 배수들은 합성수임이 자명
    if(arr[i] == 0)
      continue;
    // i를 제외한 i의 배수들을 0으로 체크
    for (j=i+i;j<=SIZE;j+=i){
      arr[j] = 0;
    }
  }

  int count = 0;
  for(i=2;i<=SIZE;i++){
    if (arr[i]!=0){
      std::cout.width(3);
      std::cout << arr[i];
      // 5개씩 출력하기 위한
      count++;
      if (count % 5== 0)
      std::cout << std::endl;
    }
  }
}
