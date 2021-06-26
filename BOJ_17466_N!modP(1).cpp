#include <iostream>
using namespace std;

long long factorial(int f, int p) {
  long long result = 1;
  for (int i = 1; i <= f; i++) {
    result *= i;
    result = result % p;
  }

  return result;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int P; cin >> P;
  int ans = factorial(N, P);
  cout << ans << "\n";

  return 0;
}
