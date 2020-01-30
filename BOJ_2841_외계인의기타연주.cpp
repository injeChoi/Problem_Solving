#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<pair<int, int> > s;
  int N, P;
  int cnt = 0;

  cin >> N >> P;
  for (int i = 0; i < N; i++) {
    int line, fret;
    cin >> line >> fret;

    if(s.empty()) {
      s.push({line, fret});
      cnt++;
    }

    else {
      if(s.top().first == line) {
        if(s.top().second < fret) {
          s.push({line, fret});
          cnt++;
        }
        else if(s.top().second > fret) {
          while(s.top().second <= line) {
            s.pop();
            cnt++;
          }
          s.push({line, fret});
          cnt++;
        }
      }

      else if(s.top().first != line) {

      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
