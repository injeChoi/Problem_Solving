#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;

ll A, B, C, LCM;

ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  if(A < B)
    swap(A, B);

  if(A == B || A == B+1)
    cout << "1" << "\n";

  else {
    ll res = (B / (A-B) + 1) * (A-B) - B;
    ll lcm = (A+res)*(B+res) / GCD(A+res, B+res);

    for (int i = 2; i*i <= A-B; ++i) {
      if((A-B) % i == 0) {
        ll t = B / i + 1;
        ll N = t * i - B;
        ll tmp = (A+N)*(B+N) / GCD(A+N,B+N);

        if(lcm > tmp) {
          res = N;
          lcm = tmp;
        }

        ll rev = (A-B) / i;
        t = B / rev + 1;
        N = t * rev - B;
        tmp = (A+N)*(B+N) / GCD(A+N,B+N);;

        if(lcm > tmp) {
          res = N;
          lcm = tmp;
        }
      }
    }

    cout << res << "\n";
  }

  return 0;
}
