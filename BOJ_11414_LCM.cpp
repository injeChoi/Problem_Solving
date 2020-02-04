#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;

ll GCD(ll a, ll b) {
  ll tmp, n;

  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }

  return a;
}

ll LCM(ll a, ll b) {
  return a * b / GCD(a, b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll A, B;
  cin >> A >> B;

  if(A < B)
    swap(A, B);

  if(A == B || A == B+1)
    cout << "1" << "\n";

  ll res = (B / (A-B) + 1) * (A-B) - B;
  ll lcm = LCM(A+res, B+res);

  for (int i = 2; i*i <= A-B; i++) {
    if(A-B % i == 0) {
      ll t = B / i + 1;
       ll N = t * i - B;
      ll tmp = LCM(A+N, B+N);

      if(lcm > tmp) {
        res = N;
        lcm = tmp;
      }

      ll rev = (A-B) / i;
      t = B / rev + 1;
      N = t * rev - B;
      tmp = LCM(A+N, B+N);

      if(lcm > tmp) {
        res = N;
        lcm = tmp;
      }
    }
  }

  cout << res << "\n";

  return 0;
}
