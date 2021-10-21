#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, cnt = 1, last;
vector<pii> conf;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool compare(pii &a, pii &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        conf.push_back({s, e});
    }
    sort(conf.begin(), conf.end(), compare);
    last = conf[0].second;

    for (int i = 1; i < N; i++) {
        if (conf[i].first >= last) {
            cnt++;
            last = conf[i].second;
        }
    }
    cout << cnt << '\n';
    return 0;
}