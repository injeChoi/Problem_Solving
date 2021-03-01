#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int T, N;
  long long P[101]; // 일정 수 이상이면 기하급수 적으로 크기 증가
  cin >> T;

  P[1] = 1;
  P[2] = 1;
  P[3] = 1;
  P[4] = 2;
  P[5] = 2;

  for (int i = 0; i < T; i++) {
    cin >> N;
    if (1 <= N &&N <= 100) {
      for (int j = 6; j <= N; j++)
        P[j] = P[j-1] + P[j-5];
      cout << P[N] << endl;
    }
  }
  return 0;
}
