#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> crane, box;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        crane.push_back(c);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int b; cin >> b;
        box.push_back(b);
    }
    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());

    if (crane.front() < box.front()) {
        cout << -1 << '\n';
        return 0;
    }
    while (!box.empty()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}