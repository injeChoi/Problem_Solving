#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int, int> &A, const pair<int, int> &B) {
  if(A.second == B.second)
    return A.first < B.first;
  else
    return A.second < B.second;
}

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;

  vector<pair<int, int> > arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end(), comp);

  for (int i = 0; i < N; i++) {
    cout << arr[i].first << " " << arr[i].second << "\n";
  }
  return 0;
}
