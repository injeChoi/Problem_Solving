#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, string, greater<string> > m;
  int N; cin >> N;

  for (int i = 0; i < N; i++) {
    string name, log;
    cin >> name >> log;
    m[name] = log;
  }

  map<string, string>::iterator iter;
  for (iter = m.begin(); iter != m.end(); iter++) {
    if(iter->second == "enter")
      cout << iter->first << "\n";
  }

  return 0;
}
