#include <iostream>
#include <vector>
using namespace std;

int N, M, result, sum, s, e;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  while(1) {
    if (sum >= M)
      sum -= v[s++];
    else if (e == N)
      break;
    else
      sum += v[e++];

    if(sum == M)
      result++;
  }

  printf("%d\n", result);
  return 0;
}
