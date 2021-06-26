#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  vector<int> dp(1000);
  vector<int> cache(1000);
  int score;
  for (int i = 1; i <= N; i++) {
    cin >> score;
    dp[i] = score;
  }

  cache[1] = dp[1];
  cache[2] = max(dp[1] + dp[2], dp[2]);
  cache[3] = max(dp[2] + dp[3], dp[1] + dp[3]);

  for (int i = 4; i <= N; i++)
    cache[i] = max(cache[i-3] + dp[i-1] + dp[i], cache[i-2] + dp[i]);

  cout << cache[N] << "\n";
  return 0;
}
