#include <bits/stdc++.h>
using namespace std;

int T, n;
int x, y;
vector<pair<int, int> > v;
vector<int> arr[102];
bool visited[102];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int manhatan(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int node) {
    visited[node] = true;
    for (int i = 0; i < arr[node].size(); i++) {
        int next = arr[node][i];
        if (!visited[next])
            DFS(next);
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;

    while (T--) {
        // 초기화
        for (int i = 0; i < 102; i++) 
            arr[i].clear();
        memset(visited, 0, sizeof(visited));
        v.clear();

        // 새로운 입력
        cin >> n;
        for (int i = 0; i < n+2; i++) {
            cin >> x >> y;
            v.push_back({x, y});
        }

        // 맨해튼 거리로 따졌을 때 1000 거리 이하 인지
        for (int i = 0; i < n+2; i++) {
            for (int j = i+1; j < n+2; j++) {
                if (manhatan(v[i], v[j]) <= 1000) {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }

        DFS(0);
        
        if (visited[n+1]) cout << "happy" << endl;
        else cout << "sad" << endl;
    }

    return 0;
}