#include <iostream>
#include <memory>
using namespace std;

int binomial(int n, int r, int binom[][100]) {
  if(r==0 || n==r)
    return binom[n][r] = 1;
  if(binom[n][r] != -1)
    return binom[n][r];
  else
    return binom[n][r] = binomial(n-1, r-1, binom) + binomial(n-1, r, binom);
}

int main() {
  int n, r;
  cout << "n 값과 r 값을 넣으시오 : ";
  cin >> n >> r;
  int binom[100][100];
  memset(binom, -1, sizeof(binom));
  cout << binomial(n, r, binom) << endl;
  return 0;
}
