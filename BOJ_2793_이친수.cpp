#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<long> v(91);
  int N; cin >> N;

  v[0] = 0;
  v[1] = 1;

  for (int i = 2; i <= N; i++)
    v[i] = v[i-1] + v[i-2];

  cout << v[N] << "\n";
  return 0;
}
