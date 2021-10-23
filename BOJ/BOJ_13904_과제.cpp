#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, MAX, answer;
vector<pii> work;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int left, score;
        cin >> left >> score;
        work.push_back({left, score});
    }
    sort(work.rbegin(), work.rend());
    MAX = work[0].first;

    for (int idx = MAX; idx >= 1; idx--) {
        vector<pii> tmp;
        for (int i = 0; i < work.size(); i++) {
            if (idx <= work[i].first) {
                tmp.push_back({work[i].second, i});
            }
        }
        if (tmp.size() != 0) {
            sort(tmp.begin(), tmp.end());
            answer += tmp.back().first;
            work.erase(work.begin() + tmp.back().second);
        }
    }
    cout << answer << '\n';
    return 0;
}