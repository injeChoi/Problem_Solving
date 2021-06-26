#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int a[4000], b[4000], c[4000], d[4000];
long long ans;
int N;
vector <int> vec_a, vec_c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vec_a.push_back(a[i] + b[j]);
			vec_c.push_back(c[i] + d[j]);
		}
	}

	sort(vec_c.begin(), vec_c.end());

	for (int i = 0; i < int(vec_a.size()); i++) {
		int key = vec_a[i] * (-1);
		int strat = 0, end = N * N - 1;
    
		while (strat <= end) {
			int mid = (strat + end) / 2;
			if (key == vec_c[mid]) {
				ans += (upper_bound(vec_c.begin(), vec_c.end() , key) - lower_bound(vec_c.begin(),vec_c.end(), key));
				break;
			}
			else if (vec_c[mid] > key) {
				end = mid - 1;
			}
			else if (vec_c[mid] < key) {
				strat = mid + 1;
			}

		}
	}
	cout << ans << "\n";
}
