#include <iostream>
using namespace std;

int fibonacci(int n) {
  int i;
  int f[41] = {1, 0, 1};

  for (i = 3; i <= 41; i++) {
    f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main(int argc, char const *argv[]) {
  int testcase;
  cin >> testcase;

  for (int i = 0; i < testcase; i++) {
    int n;
    cin >> n;
    cout << fibonacci(n) << " " << fibonacci(n+1) << endl;
  }

  return 0;
}
