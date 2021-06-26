#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

bool comp(const string &A, const string &B) {
  if(A.size() == B.size())
    return A < B;
  else
    return A.size() < B.size();
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int cnt = N;

  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    v.push_back(str);
  }

  sort(v.begin(), v.end(), comp);
  vector<string>::iterator iter;
  vector<string>::iterator end = unique(v.begin(), v.end());

  for (iter = v.begin(); iter != end; iter++) {
    cout << *iter << "\n";
  }

  return 0;
}
