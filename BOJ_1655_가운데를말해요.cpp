#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;

    if(max_heap.empty())
      max_heap.push(num);

    else if(max_heap.size() == min_heap.size())
      max_heap.push(num);

    else
      min_heap.push(num);

    if(!max_heap.empty() && !min_heap.empty() && max_heap.top() >= min_heap.top()) {
      int max_top = max_heap.top();
      int min_top = min_heap.top();

      max_heap.pop();
      min_heap.pop();

      max_heap.push(min_top);
      min_heap.push(max_top);
    }

    cout << max_heap.top() << "\n";
  }

  return 0;
}
