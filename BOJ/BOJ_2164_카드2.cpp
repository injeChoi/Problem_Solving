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

  for (int i = 1; i <= N; i++)
    q.push(i);

  while(q.size() > 1) {
    q.pop();  // 제일 위에 카드 버림
    q.push(q.front());  //남아있는 카드 중 제일 위의 카드를 맨 아래에 추가
    q.pop();  // 제일 위에 카드 제거
  }

  cout << q.front() << "\n";

  return 0;
}
