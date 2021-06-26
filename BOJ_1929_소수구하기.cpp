#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define SIZE 1000000
int SOE[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M, N;
  cin >> M >> N;

  for (int i = 2; i <= SIZE; i++)
    SOE[i] = i;

  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(SOE[i] == 0)
      continue;

    else
      for (int j = i+i; j <= SIZE; j += i)
        SOE[j] = 0;
  }

  for (int i = M; i <= N; i++) {
    if(SOE[i] == i)
      cout << i << "\n";
  }

  return 0;
}
