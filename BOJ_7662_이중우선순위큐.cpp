#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<long long> d;
  priority_queue<string> pq;
  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int k; cin >> k;

    for (int j = 0; j < k; j++) {
      char c; cin >> c;
      long long num;

      if(c == 'I') {
        cin >> num;
        d.push_back(num);
      }

      else {
        cin >> num;
        if(!d.empty()) {
          if(num == 1)
            d.pop_back();
          else
            d.pop_front();
        }
        else
          pq.push("EMPTY");
      }

      sort(d.begin(), d.end());
    }

    if(!d.empty())
      cout << d.back() << " " << d.front() << "\n";
    else
      cout << pq.top() << "\n";
  }

  return 0;
}

// #include <map>
// #include <iostream>
// using namespace std;
//
// int main(){
//   int T; cin >> T;
//
//   for(int i = 0; i < T; i++){
//     map<int,int> m;
//     int N; cin >> N;
//
//     for(int j = 0; j < N; j++){
//       char c; int n;
//       cin >> c; cin >> n;
//
//       if(c == 'I')
//         if(m.find(n) == m.end())
//           m[n]=0;
//         else
//           m[n]++;
//
//       else if(c == 'D' && m.size()) {
//         map<int,int>::iterator it;
//         if(n == 1)
//           it = --m.end();
//         else
//           it = m.begin();
//
//         if(it->second==0)
//           m.erase(it);
//         else
//           it->second--;
//       }
//
//     }
//
//     if(m.size() == 0)
//       cout << "EMPTY" << "\n";
//     else
//       cout << (--m.end())->first << " " << m.begin()->first << "\n";
//   }
//
//   return 0;
// }
