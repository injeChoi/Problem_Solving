#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000000
long long dp[101][10];

int main(int argc, char const *argv[]) {
  int N;
  long long sum = 0;
  cin >> N;

  for (int i = 0; i <= 9; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0) {
        dp[i][j] = dp[i-1][j+1] % MOD;
      }
      else if (j == 9) {
        dp[i][j] = dp[i-1][j-1] % MOD;
      }
      else {
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % MOD;
      }
    }
  }

  for (int i = 1; i <= 9; i++) {
    sum = (sum + dp[N][i]) % MOD;
  }

  cout << sum << endl;

  return 0;
}
