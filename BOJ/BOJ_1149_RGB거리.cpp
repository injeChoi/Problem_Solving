#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  vector<vector<int> > dp(N, vector<int>(3));

  for (int i = 0; i < N; i++)
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

  for (int i = 1; i < N; i++) {
    dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
    dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
    dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
  }

  int temp = min(dp[N-1][0], dp[N-1][1]);
  temp = min(temp, dp[N-1][2]);

  cout << temp << "\n";
  return 0;
}
