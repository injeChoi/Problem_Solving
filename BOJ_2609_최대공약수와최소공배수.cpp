#include <iostream>
using namespace std;

int GCD(int a, int b) {
  int tmp, n;

  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }

  return a;
}

int LCM(int a, int b) {
  return a * b / GCD(a, b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  cout << GCD(N, M) << "\n" << LCM(N, M) << "\n";

  return 0;
}
