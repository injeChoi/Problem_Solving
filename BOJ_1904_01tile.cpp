#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int F[1000001];
  int N;
  cin >> N;

  if (N > 0) {
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i <= N; i++) {
      F[i] = (F[i-1] + F[i-2]) % 15746;
    }
    cout << F[N] << endl;
  }

  return 0;
}
