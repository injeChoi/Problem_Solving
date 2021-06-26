#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 10000000
int arr[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;

  for (int i = 2; i <= SIZE; i++)
    arr[i] = i;

  for (int i = 2; i < sqrt(SIZE); i++) {
    if(arr[i] == 0)
      continue;

    else
      for (int j = i+i; j <= SIZE; j += i)
        arr[j] = 0;
  }

  for (int i = 2; i <= SIZE; i++)
    if(arr[i] != 0)
      while(N % i == 0) {
        N = N / i;
        cout << i << "\n";
      }

  return 0;
}
