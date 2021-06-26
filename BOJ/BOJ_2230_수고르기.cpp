#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> v(100001);
  int N, M, i = 0, j = 1;
  int res = 2000000000;

  cin >> N >> M;

  for (int i = 0; i < N; i++) 
    cin >> v[i];

  sort(v.begin(), v.begin()+N);

  while(j != N) {
    if(v[j] - v[i] < M) {
      j++;
      continue;
    }

    else if(v[j] - v[i] == M) {
      cout << M << "\n";
      return 0;
    }

    else
      res = min(res, v[j] - v[i]);

    i++;
  }

  cout << res << "\n";

  return 0;
}
