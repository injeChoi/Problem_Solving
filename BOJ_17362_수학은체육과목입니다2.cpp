#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  if (N % 8 >= 1 && N % 8 <= 5)
    cout << N % 8 << endl;
  else if (N % 8 == 6)
    cout << 4 << endl;
  else if (N % 8 == 7)
    cout << 3 << endl;
  else if (N % 8 == 0)
    cout << 2 << endl;

  return 0;
}
