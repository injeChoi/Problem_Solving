#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool comp(const int &A, const int &B) {
  return A > B;
}

int main(int argc, char const *argv[]) {
  int N; cin >> N;
  int len = N;
  int cnt = -1;
  vector<int> v;

  while(len > 0) {
    len = len / 10;
    cnt++;
  }

  int idx = cnt + 1;
  for (int i = 0; i < idx; i++) {
    int res = N / pow(10, cnt);
    v.push_back(res);
    N = N - res * pow(10, cnt);
    cnt--;
  }

  sort(v.begin(), v.end(), comp);

  for (int i = 0; i < idx; i++) {
    cout << v[i];
  }

  cout << "\n";
  return 0;
}
