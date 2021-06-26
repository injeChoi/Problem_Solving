#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

stack<char> rs;
stack<char> ls;
int M;
char append; // P cmd용 덧붙일 문자
char ch[100001];
void cursor(char);

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char cmd, temp;
  cin >> ch;
  cin >> M;

  int len  = strlen(ch);
  for (int i = 0; i < len; i++)
    ls.push(ch[i]);

  for (int i = 0; i < M; i++) {
    cin >> cmd;

    if (cmd == 'P')
      cin >> append;

    cursor(cmd);
  }

  while(!ls.empty()) {
    temp = ls.top();
    ls.pop();
    rs.push(temp);
  }

  while(!rs.empty()) {
    cout << rs.top();
    rs.pop();
  }
  cout << endl;

  return 0;
}

void cursor(char cmd) {
  char tmp;

  if (cmd == 'L' && !ls.empty()) {
    tmp = ls.top();
    ls.pop();
    rs.push(tmp);
  }

  if (cmd == 'D' && !rs.empty()) {
    tmp = rs.top();
    rs.pop();
    ls.push(tmp);
  }

  if (cmd == 'B' && !ls.empty()) {
    ls.pop();
  }

  if (cmd == 'P') {
    ls.push(append);
  }
}
