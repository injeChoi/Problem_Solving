#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, num, resA, resB;
vector<int> v;

bool compare(int a, int b) {
  return abs(a) < abs(b);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int min = 2100000000;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < N-1; i++) {
    if(abs(v[i] + v[i+1]) < min) {
      min = abs(v[i] + v[i+1]);
      resA = v[i];
      resB = v[i+1];
    }
  }
  if(resA < resB)
    cout << resA << " " << resB << endl;
  else
    cout << resB << " " << resA << endl;
  return 0;
}
