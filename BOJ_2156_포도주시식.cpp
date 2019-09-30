#include <iostream>
#include <algorithm>
using namespace std;

int Wine[10001];
int dp[10001][3];

int main(int argc, char const *argv[]) {
  int N, res = 0;
  //freopen("input.txt", "r", stdin);
  cin >> N;

  Wine[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> Wine[i];
  }

  for (int i = 0; i < 3; i++) {
    dp[0][i] = Wine[0];
  }

  for (int i = 1; i <= N; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][0] = max(dp[i][0], dp[i-1][2]);
    dp[i][1] = dp[i-1][0] + Wine[i];
    dp[i][2] = dp[i-1][1] + Wine[i];
  }

  res = max(dp[N][0], dp[N][1]);
  res = max(res, dp[N][2]);

  cout << res << endl;

  return 0;
}
