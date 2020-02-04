#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;

  while(cin >> N >> M) {
    long long tmp = M, ans = 1;

    for (int i = 2; i*i <= tmp; i++)
    {
      int M_two = 0;
      while(M % i == 0)
      {
        M /= i;
        M_two += 1;
      }
      if(M_two) {
        int N_two = 0;
        for (int j = i; j <= N; j *= i)
        N_two += N / j;

        for (int j = 0; j < min(N_two, M_two); j++)
        ans *= i;
      }

      if(M < i)
      break;
    }

    if (M > 1 && M <= N)
    ans *= M;

    cout << ans << "\n";
  }

  return 0;
}
