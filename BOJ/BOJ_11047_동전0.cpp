#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> value;
int cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int v; cin >> v;
        value.push_back(v);
    }
    for (int i = value.size()-1; i >= 0; i--) {
        if (value[i] <= K) {
            cnt += K / value[i];
            K %= value[i];
        }
    }
    cout << cnt << '\n';
    return 0;
}