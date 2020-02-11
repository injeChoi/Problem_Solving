#include <iostream>
using namespace std;

int B[11]={0};

int bin(int n, int k) {
  int i, j;
  for(i = 0; i <= n; i++) {
    for(j = i; j >= 0; j--) {
      if (j == 0 || j == i)
        B[j] = 1;

      else
        B[j] = B[j-1] + B[j];
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
