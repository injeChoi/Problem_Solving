#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define SIZE 123456*2
int SOE[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 2; i <= SIZE; i++)
    SOE[i] = i;

  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(SOE[i] == 0)
      continue;

    else
      for (int j = i+i; j <= SIZE; j += i)
        SOE[j] = 0;
  }

  while(1) {
    int N; cin >> N;

    if(N > 0) {
      int cnt = 0;
      for (int i = N+1; i <= 2*N; i++) {
        if(SOE[i] == i)
          cnt++;
      }
      cout << cnt << "\n";
    }

    else
      break;
  }

  return 0;
}
