#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, I;
  cin >> N >> I;

  vector<string> arr;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    arr.push_back(str);
  }

  sort(arr.begin(), arr.end());

  cout << arr[I-1] << endl;

  return 0;
}
