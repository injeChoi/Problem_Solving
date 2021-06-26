#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;
  stack<char> s;

  for (int i = 0; i < T; i++) {
    string str; cin >> str;

    for (int j = 0; j < str.length(); j++) {
      if(str[j] == '(' || s.empty())
        s.push(str[j]);

      else if(s.top() == '(')
        s.pop();
    }

    if(s.empty())
      cout << "YES" "\n";

    else
      cout << "NO" << "\n" ;

    while(!s.empty())
      s.pop();
  }

  return 0;
}
