#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> result;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;
    while(T--) {
        vector<int> L;
        int MAX = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int l; cin >> l;
            L.push_back(l);
        }
        sort(L.begin(), L.end());
        for (int i = 0; i < N-2; i++) {
            MAX = max(MAX, abs(L[i] - L[i+2]));
        }
        result.push_back(MAX);
    }
    for (int item : result) {
        cout << item << '\n';
    }
    return 0;
}