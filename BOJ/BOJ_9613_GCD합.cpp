#include <iostream>
#include <vector>
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

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    long sum_gcd = 0;
    vector<int> v;

    for (int j = 0; j < N; j++) {
      int num; cin >> num;
      v.push_back(num);
    }

    for (int j = 0; j < N-1; j++)
      for (int k = j+1; k < N; k++)
        sum_gcd += GCD(v[j], v[k]);

    cout << sum_gcd << "\n";
  }

  return 0;
}
