#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N, D, S;

int GCD(int a, int b) {
  int tmp, n;

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

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;

        if (S >= num)
            v.push_back(S - num);
        else
            v.push_back(num - S);
    }

    D = GCD(v[0], v[1]);
    for (int i = 2; i < N; i++)
        D = GCD(D, v[i]);

    cout << D << endl;

    return 0;
}
