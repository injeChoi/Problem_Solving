#include <iostream>
using namespace std;

int cache[11];
int N;

int dp() {
  int i;

  cache[1] = 1;
  cache[2] = 2;
  cache[3] = 4;

  for(i=4; i <= N; i++)
    cache[i] = cache[i-1] + cache[i-2] + cache[i-3];

  return cache[N];
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    cout << dp() << endl;
  }

  return 0;
}
