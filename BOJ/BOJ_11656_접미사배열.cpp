#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string str;
  cin >> str;

  vector<string> s;
  for (int i = 0; i < str.length(); i++) {
    s.push_back(str.substr(i, str.length()));
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < str.length(); i++) {
    cout << s[i] << "\n";
  }
  return 0;
}
