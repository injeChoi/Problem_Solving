#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase; cin >> testcase;

  for (int i = 0; i < testcase; i++) {
    priority_queue<int, vector<int>, less<int> > pq;
    queue<pair<int, int> > q;
    int N; cin >> N;
    int pos; cin >> pos;
    int cnt = 0;

    for (int j = 0; j < N; j++) {
      int num; cin >> num;
      q.push({j, num});
      pq.push(num);
    }

    while(!q.empty()) {
      if(q.front().second == pq.top()) {
        cnt++;
        pq.pop();
        if(q.front().first == pos) {
          cout << cnt << "\n";
          break;
        }
      }
      else {
        q.push({q.front().first, q.front().second});
      }
      q.pop();
    }
  }

  return 0;
}
