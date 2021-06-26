#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, int> m1;
  map<int, string> m2;
  string str;
  int N, Q;
  cin >> N >> Q;

  for (int i = 1; i <= N; i++) {
    cin >> str;
    m1.insert({str, i});
    m2.insert({i, str});
  }

  string obs;
  for (int i = 0; i < Q; i++) {
    cin >> obs;

    if(isdigit(obs[0]) == 0) {
      map<string, int>::iterator iter_str = m1.find(obs);
      cout << iter_str->second << "\n";
    }

    else {
      int digit = stoi(obs);
      map<int, string>::iterator iter_int = m2.find(digit);
      cout << iter_int->second << "\n";
    }
  }

  return 0;
}
