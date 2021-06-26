#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;
  int k;
  for (int i = 0; i < T; i++) {
    multiset<int> ms;
    cin >> k;

    for(int j = 0; j < k; j++) {
      char c; cin >> c;
      int num; cin >> num;

      if(c == 'I')
        ms.insert(num);

      else if(c == 'D') {
        if(ms.empty())
          continue;

        else if(num == 1)
          ms.erase(--ms.end());

        else
          ms.erase(ms.begin());
      }
    }

    if(ms.empty())
      cout << "EMPTY" << "\n";
    else
      cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
  }

  return 0;
}
