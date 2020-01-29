#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

struct comp {
  bool operator() (const int &A, const int &B) {
    if(abs(A) > abs(B))
      return true;

    else if(abs(A) == abs(B)) {
      if(A > B)
        return true;
      else
        return false;
    }
    else
      return false;
  }
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  priority_queue<int, vector<int>, comp> pq;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;

    if(num != 0)
      pq.push(num);

    else if(num == 0) {
      if(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      }
      else
        cout << "0" << "\n";
    }
  }

  return 0;
}
