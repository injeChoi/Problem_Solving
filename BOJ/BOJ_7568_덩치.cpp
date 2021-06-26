#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int N, x, y, cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++) {
        cnt = 1;
        for (int j = 0; j < N; j++) 
            if (v[i].first < v[j].first && v[i].second < v[j].second) 
                cnt++;
        cout << cnt << " ";
    }
    return 0;
}
