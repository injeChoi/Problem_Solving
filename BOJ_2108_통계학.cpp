#include <bits/stdc++.h>
using namespace std;

int N, total, mode, idx, maxVisit;
int minN = 4000, maxN = -4000;
int visited[8001];
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
        total += v[i];
        visited[v[i] + 4000]++;
        maxN = max(maxN, v[i]);
		minN = min(minN, v[i]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8001; i++) {
		if (visited[i] > maxVisit) {
			maxVisit = visited[i];
			idx = i;
			mode = i - 4000;
		}
	}
	
	for (int i = 0; i < 8001; i++) {
		if ((visited[i] == maxVisit) && (idx < i)) {
			mode = i - 4000;
			break;
		}
	}

    cout << round(total / (double)N) << endl;
	cout << v[N/2]<< endl;
	cout << mode << endl;
 	cout << maxN - minN << endl;

    return 0;
}