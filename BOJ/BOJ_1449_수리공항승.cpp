#include <bits/stdc++.h>
using namespace std;

int N, L, cnt;
vector<int> tapes;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        tapes.push_back(n);
    }
    if (L == 1) {
        cout << tapes.size() << '\n';
        return 0;
    }
    sort(tapes.begin(), tapes.end());

    for (int i = 0; i < tapes.size(); i++) {
        for (int j = i+1; j < tapes.size(); j++) {
            if (tapes[j] - tapes[i] > L-1) {
                cnt++;
                i = j-1;
                break;
            }
        }
    }
    cout << cnt+1 << '\n';
    return 0;
}