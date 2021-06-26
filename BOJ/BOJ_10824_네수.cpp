#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C, D;
  cin >> A >> B >> C >> D;

  string s1 = to_string(A) + to_string(B);
  string s2 = to_string(C) + to_string(D);

  long long ans = stoull(s1) + stoull(s2);

  cout << ans << endl;
  return 0;
}
