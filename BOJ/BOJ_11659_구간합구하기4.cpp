#include <bits/stdc++.h>
using namespace std;

int N, M;
int dp[100001];
int cache[100001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> dp[i];
    }
    cache[1] = dp[1];

    for (int i = 2; i <= N; i++) {
        cache[i] = cache[i-1] + dp[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cout << cache[b] - cache[a-1] << '\n';
    }
    return 0;
}