#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<int> s[7];  // 기타는 6줄
  int N, P;
  int cnt = 0;

  cin >> N >> P;
  for (int i = 0; i < N; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;

    if(s[p.first].empty()) {
      s[p.first].push(p.second);
      cnt++;
    }

    else {
      if(s[p.first].top() < p.second) {
        s[p.first].push(p.second);
        cnt++;
      }

      else if(s[p.first].top() == p.second)
        continue;

      else {
        while(!s[p.first].empty() && s[p.first].top() > p.second) {
          s[p.first].pop();
          cnt++;
        }

        if(!s[p.first].empty() && s[p.first].top() == p.second)
          continue;

        s[p.first].push(p.second);
        cnt++;
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
