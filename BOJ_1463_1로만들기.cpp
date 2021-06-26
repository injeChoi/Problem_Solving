#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N; cin >> N;
  int ans;
  vector<int> v(1000001);

  v[1] = 0;
  for (int i = 2; i <= N; i++) {
    v[i] = v[i-1] + 1;

    if(i % 3 == 0)
      v[i] = min(v[i], v[i/3]+1);

    if(i % 2 == 0)
      v[i] = min(v[i], v[i/2]+1);

    ans = v[i];
  }

  cout << ans;

  return 0;
}
