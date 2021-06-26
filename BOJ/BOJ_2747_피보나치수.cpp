#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;

  v.push_back(0);
  v.push_back(1);
  for (int i = 2; i <= N; i++)
    v.push_back(v[i-1] + v[i-2]);

  cout << v[N] << "\n";

  return 0;
}
