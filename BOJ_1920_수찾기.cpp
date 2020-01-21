#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> v;
  vector<int> f;

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int num1; cin >> num1;
     v.push_back(num1);
  }
  int M; cin >> M;
  vector<int> res(M);
  for (int i = 0; i < M; i++) {
    int num2; cin >> num2;
    f.push_back(num2);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(f[i] == v[j]) {
        res[i]++;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    cout << res[i] << "\n";
  }

  return 0;
}
