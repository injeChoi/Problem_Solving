#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  deque<int> d;

  for (int i = 0; i < N; i++) {
    string str; cin >> str;

    if(str == "push_back") {
      int num; cin >> num;
      d.push_back(num);
    }

    else if(str == "push_front") {
      int num; cin >> num;
      d.push_front(num);
    }

    else if(str == "front") {
      if(!d.empty())
        cout << d.front() << "\n";
      else
        cout << "-1" << "\n";
    }

    else if(str == "back") {
      if(!d.empty())
        cout << d.back() << "\n";
      else
        cout << "-1" << "\n";
    }

    else if(str == "size") {
      cout << d.size() << "\n";
    }

    else if(str == "empty") {
      if(d.empty())
        cout << "1" << "\n";
      else
        cout << "0" << "\n";
    }

    else if(str == "pop_front") {
      if(d.empty())
        cout << "-1" << "\n";
      else {
        cout << d.front() << "\n";
        d.pop_front();
      }
    }

    else if(str == "pop_back") {
      if(d.empty())
        cout << "-1" << "\n";
      else {
        cout << d.back() << "\n";
        d.pop_back();
      }
    }
  }
  return 0;
}
