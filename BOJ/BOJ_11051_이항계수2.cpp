#include <iostream>
using namespace std;

long B[1001]={0};

long bin(int n, int k) {
  int i, j;
  for(i = 0; i <= n; i++) {
    for(j = i; j >= 0; j--) {
      if (j == 0 || j == i)
        B[j] = 1;

      else
        B[j] = (B[j-1] + B[j]) % 10007;
    }
  }
  return B[k];
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  cout << bin(N, K) << "\n";
  return 0;
}
