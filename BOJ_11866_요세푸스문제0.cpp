#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<int> q;
  int N; cin >> N;
  int K; cin >> K;

  for (int i = 1; i <= N; i++)
    q.push(i);

  cout << "<";

  while(!q.empty()) {
    for (int i = 1; i < K; i++) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    q.pop();
    
    if(!q.empty())
      cout << ", ";
  }
  cout << ">" << "\n";

  return 0;
}
