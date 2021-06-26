#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define SIZE 1000000
bool SOE[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 2; i <= SIZE; i++)
    SOE[i] = true;


  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(SOE[i] == 0)
      continue;
    else
      for (int j = i+i; j <= SIZE; j += i)
        SOE[j] = false;
  }

  while (1) {
    int test; cin >> test;
    int idx = 0, i = 0;

    if (test == 0)
      break;

    for (i = 3; i < test; i++) {
      if (SOE[i]) {
        idx = test - i;
        if (SOE[idx]) {
          printf("%d = %d + %d\n", test, i, idx);
          break;
        }
      }
    }

    if (i == test)
      cout << "Goldbach's conjecture is wrong." << endl;
  }

  return 0;
}
