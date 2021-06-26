#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N;
int num;
long long total = 0;
unsigned long long ans;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    v.push_back(num);
    total += v[i];
  }

  for (int i = 0; i < N-1; i++) {
		total -= v[i];
		ans += total * v[i];
	}

  cout << ans << "\n";

  return 0;
}
