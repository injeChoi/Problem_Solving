/*
stack을 index로 활용하여 시간 복잡도를 줄이는게 키 포인트
index값을 스택으로 쌓아 n번째 까지 비교 후
n번째에서 ans 벡터 값을 변동시키는 조건이 생기면  
스택 값을 pop하면서 index값을 낮추면서 다시 비교하는 방식
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> v;
stack<int> s;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    v.push_back(num);
  }

  vector<int> ans(v.size(), -1); // vector v에 값을 넣고 나서야 v.size를 알 수 있다.

  for (int i = 0; i < v.size(); i++) {
    while (!s.empty() && v[i] > v[s.top()]) {
      ans[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  cout << endl;

  return 0;
}
