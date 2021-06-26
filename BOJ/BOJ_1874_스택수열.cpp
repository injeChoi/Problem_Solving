#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int idx = 0;
  vector<int> v1;
  stack<int> s;
  vector<char> arr;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    v1.push_back(num);
  }

  vector<int> v2(v1); // v1을 v2에 복사
  sort(v1.begin(), v1.end());

  for (int i = 0; i < N; i++) {
    s.push(v1[i]);

    if(s.top() != v2[idx])
      arr.push_back('+'); // 수열 index에 맞지 않으면 계속 스택에 추가

    else {
      arr.push_back('+'); // 수열 index에 맞으면 여기까지만 추가
      while(!s.empty()) {
        if (s.top() == v2[idx]) { // 수열 index에 맞는 숫자를 뺌
          arr.push_back('-');
          s.pop();
          idx++;
        }
        else
          break;
      }
    }
  }

  if(s.empty())
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << "\n";
    }
  else
    cout << "NO" << "\n";

  return 0;
}
