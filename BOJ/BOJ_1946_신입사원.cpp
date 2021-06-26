#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int T, N, cnt;
    vector<pair<int, int> > v;
    cin >> T;
    
    while (T--) {
        cnt = 1;
        cin >> N;
        int s, m;
        for (int i = 0; i < N; i++) {
            cin >> s >> m;
            v.push_back({s, m});
        }
        sort(v.begin(), v.end());
        
        int rank = v[0].second;
        for (int i = 1; i < N; i++) {
            if (v[i].second < rank) {
                cnt++;
                rank = v[i].second;
            }
        }
        cout << cnt << endl;
        v.clear();
    }

    return 0;
}
