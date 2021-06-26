#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 100000
int arr[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    int cnt[SIZE+1];

    for (int j = 2; j <= SIZE; j++)
      arr[j] = j;

    for (int j = 2; j <= sqrt(SIZE); j++) {
      if(arr[j] == 0)
        continue;

      else
        for (int k = j+j; k <= SIZE; k += j)
          arr[k] = 0;
    }

    for (int j = 2; j <= SIZE; j++) {
      cnt[j] = 0;

      if(arr[j] != 0)
        while(N % j == 0) {
          N = N / j;
          cnt[j]++;
        }
    }

    for (int j = 2; j <= SIZE; j++)
      if(cnt[j] != 0)
        cout << j << " " << cnt[j] << "\n";
  }

  return 0;
}
