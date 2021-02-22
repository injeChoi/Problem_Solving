#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
vector<int> v, dist;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N-1; i++) 
        dist.push_back(v[i+1] - v[i]);
    
    sort(dist.begin(), dist.end());

    for (int i = 0; i < N-K; i++) 
        ans += dist[i];

    cout << ans << endl;

    return 0;
}