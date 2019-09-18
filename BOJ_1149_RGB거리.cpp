#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  int temp;
  int dp[1001][3] = { 0 }; // dp[ ][0] = Red, dp[ ][1] = Green, dp[ ][2] = Blue

  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];


  for (int i = 1; i <= N; i++) {
    dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
    dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
    dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
  }

  temp = min(dp[N][0], dp[N][1]);
  temp = min(temp, dp[N][2]);

  cout << temp << endl;

  return 0;
}
