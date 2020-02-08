#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  multimap<int, int> m;
  int N, num, mid;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> num;

    if(m.empty()) {
      m.insert({num, i});
      multimap<int, int>::iterator iter;
      for (iter = m.begin(); iter != m.end(); iter++)
        cout << iter->second << "\n";
    }

    else {
      m.insert({num, i});
      int mid;
      if(m.size() % 2 == 0)
        mid = m.size() / 2;

      else
        mid = m.size() / 2 + 1;

      multimap<int, int>::iterator iter;
      for (iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second == mid)
          cout << iter->first << "\n";
      }
    }
  }

  return 0;
}
