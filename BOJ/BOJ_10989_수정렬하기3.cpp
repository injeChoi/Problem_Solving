#include <iostream>
#include <algorithm>
using namespace std;

int v[10001];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  int i;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    v[num]++;
  }

  for (i = 1; i <= 10000; ++i) {
    for (int j = 0; j < v[i]; ++j) {
      cout << i << "\n";
    }
  }

  return 0;
}
