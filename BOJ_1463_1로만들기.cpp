#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000001];

int main(int argc, char const *argv[]) {
  int N, res = 0;
  cin >> N;

  dp[1] = 0;
  for (int i = 2; i <= N; i++) {
    if(i%3 == 0)
      dp[i] = min(dp[i-1] + 1, dp[i/3] + 1);

    else if(i%2 == 0)
      dp[i] = min(dp[i-1] + 1, dp[i/2] + 1);

    else
      dp[i] = dp[i-1] + 1;

    res = dp[i];
  }

  cout << res << endl;

  return 0;
}
