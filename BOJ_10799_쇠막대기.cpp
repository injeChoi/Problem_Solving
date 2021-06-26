#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str; cin >> str;
  int stick = 0, ans = 0;
  stack<int> s;
  char before;

  for (int i = 0; i < str.length(); i++) {
    s.push(str[i]);

    if(s.top() == '(')
       stick++;

    else {
      stick--;

      if(before == '(')
        ans += stick;

      else
        ans++;
    }
    before = s.top();
  }

  cout << ans << "\n";
  return 0;
}
