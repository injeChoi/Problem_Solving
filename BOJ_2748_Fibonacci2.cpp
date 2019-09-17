#include <iostream>
using namespace std;

int main() {
  long F[90];
  int i;
  int n;
  cin >> n;

  F[0] = 0;
  if (n > 0) {
    F[1] = 1;
    for (i = 2; i <= n; i++) {
      F[i] = F[i-1] + F[i-2];
    }
  }
  cout << F[n] << endl;
  return 0;
}
