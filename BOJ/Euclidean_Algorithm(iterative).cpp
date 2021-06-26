#include <iostream>
using namespace std;

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
  int a, b;
  cin >> a >> b;

  cout << GCD(a, b) << endl;

  return 0;
}
