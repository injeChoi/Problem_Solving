#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define SIZE 10000000
long long SOE[SIZE+1];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 2; i <= SIZE; i++)
    SOE[i] = i;

  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(SOE[i] == 0)
      continue;

    else
      for (int j = i+i; j <= SIZE; j += i)
        SOE[j] = 0;
  }

  long long A, B, cnt = 0;
  cin >> A >> B;

  for (int i = 2; i <= SIZE; i++) {
    if(SOE[i] != 0) {
      long long num = SOE[i];
      while (SOE[i] <= B / num)
      {
        if (SOE[i] * num >= A)
          cnt++;
        num *= SOE[i];
      }
    }
  }

  cout << cnt << "\n";

  return 0;
}
