#include <iostream>
#include <algorithm>
using namespace std;

int Floor[1000];
int dp[1000];

int main(int argc, char const *argv[]) {
  int N, score = 0;
  //freopen("input.txt", "r", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> score;
    Floor[i] = score;
  }

  dp[0] = Floor[0];
  dp[1] = max(Floor[0]+Floor[1],Floor[1]);
  dp[2] = max(Floor[0]+Floor[2],Floor[1]+Floor[2]);

  for (int i = 3; i < N; i++) {
      dp[i] = max(dp[i-3] + Floor[i-1] + Floor[i], dp[i-2] + Floor[i]);
      score = dp[i];
    }

  cout << score << endl;

  return 0;
}
