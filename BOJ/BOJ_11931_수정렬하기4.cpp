#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool desc(int a, int b) {
  return a > b;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, num;
  cin >> N;

  vector<int> v;

  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end(), desc);

  for (int i = 0; i < N; i++) {
    printf("%d\n", v[i]);
  }
  return 0;
}
