#include <iostream>
#include <vector>
using namespace std;

pair<long long, long long> Zero(long long N) {
  long long two = 0, five = 0;

  for (long long i = 2; i <= N; i *= 2)
    two += N / i;

  for (long long i = 5; i <= N; i *= 5)
    five += N / i;

  return {two, five};
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<pair<long long, long long> > v;
  v.push_back(Zero(N));
  v.push_back(Zero(M));
  v.push_back(Zero(N-M));

  cout << min(v[0].first-v[1].first-v[2].first, v[0].second-v[1].second-v[2].second) << "\n";

  return 0;
}
