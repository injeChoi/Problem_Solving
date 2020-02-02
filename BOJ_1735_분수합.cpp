#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 30000
int arr[SIZE+1];

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

int LCM(int a, int b) {
  return a * b / GCD(a, b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int u1, u2, d1, d2;
  cin >> u1 >> d1;
  cin >> u2 >> d2;

  int lcm = LCM(d1, d2);
  int num = lcm/d1*u1 + lcm/d2*u2;

  for(int i = 2; i <= SIZE; i++)
    arr[i] = i;

  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(arr[i] == 0)
      continue;

    for (int j = i+i; j <= SIZE; j += i)
      arr[j] = 0;
  }

  for (int i = 2; i <= SIZE; i++) {
    if(arr[i] != 0) {
      while(num % i == 0 && lcm % i == 0) {
        num = num / i;
        lcm = lcm / i;
      }
    }
  }

  cout << num << " " << lcm << "\n";

  return 0;
}
