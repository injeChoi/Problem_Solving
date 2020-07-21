#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<char> s;
char ch[1001];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;
  getchar(); // 입력 버퍼에 개행 문자가 남아있는걸 소거한다

  for (int testcase = 0; testcase < T; testcase++) {
    cin.getline(ch, 1001);

    for (int i = 0; i < 1001; i++) {
      if (ch[i] == ' ') {
        while(!s.empty()) {
          cout << s.top();
          s.pop();
        }
        cout << " ";
      }
      else if (ch[i] == '\0') {
        while(!s.empty()) {
          cout << s.top();
          s.pop();
        }
        break;
      }
      else
        s.push(ch[i]);
    }
    cout << endl;
  }

  return 0;
}
