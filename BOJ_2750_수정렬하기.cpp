#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  int num;
  cin >> N;

  vector<int> arr;

  for (int i = 0; i < N; i++) {
    cin >> num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < N; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
