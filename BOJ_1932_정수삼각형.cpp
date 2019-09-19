#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][1000];

int main(int argc, char const *argv[]) {
  int Floor, res = 0;
  cin >> Floor;

  for (int i = 0; i < Floor; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> dp[i][j];
    }
  }

  for (int i = 1; i < Floor; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] += dp[i-1][j];
      }

      else if (j == i) {
        dp[i][j] += dp[i-1][j-1];
      }

      else {
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j];
      }
    }
  }

  for (int k = 0; k < Floor; k++) {
    res = max(res, dp[Floor-1][k]);
  }
  cout << res << endl;

  return 0;
}
