#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define SIZE 1000
vector<int> v;
vector<int> SOE(SIZE+1);

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    v.push_back(num);
  }

  for (int i = 2; i <= SIZE; i++)
    SOE[i] = i;

  for (int i = 2; i <= sqrt(SIZE); i++) {
    if(SOE[i] == 0)
      continue;

    else
      for (int j = i+i; j <= SIZE; j += i)
        SOE[j] = 0;
  }

  for (int i = 0; i < N; i++)
    for (int j = 2; j <= SIZE; j++)
      if(v[i] == SOE[j])
        cnt++;

  cout << cnt << "\n";

  return 0;
}
