#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BinarySearch(vector<int>& arr, int start, int end, int key) {
  int mid = (start + end) / 2;

  if (arr[mid] == key) {
    cout << "1" << "\n";
    return;
  }

  if (start > end) {
    cout << "0" << "\n";
    return;
  }

  if (arr[mid] > key)
    BinarySearch(arr, start, mid-1, key);

  else if (arr[mid] < key)
    BinarySearch(arr, mid+1, end, key);

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v;
  int num, src;

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
     cin >> num;
     v.push_back(num);
  }

  sort(v.begin(), v.end());

  int M; cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> src;
    BinarySearch(v, 0, N-1, src);
  }

  return 0;
}
