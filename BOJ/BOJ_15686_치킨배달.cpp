#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, MAX = 987654321, ans = 987654321;
int village[50][50];
vector<pii> house, chicken;
bool visited[13];

int distance(pii a, pii b) {    // 맨해튼 거리 
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx, int cnt) {
    // 종료 조건
    if (cnt == M) {
        int tmp = 0;
        for (int i = 0; i < house.size(); i++) {
            int dist = MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (visited[j]) {
                    dist = min(dist, distance(house[i], chicken[j]));
                }
            }
            tmp += dist;
        }
        ans = min(ans, tmp);
        return;
    }

    if (idx == chicken.size()) {
        return;
    }
    visited[idx] = true;
    DFS(idx+1, cnt+1);
    visited[idx] = false;
    DFS(idx+1, cnt);
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> village[i][j];
            if (village[i][j] == 1) {
                house.push_back({i, j});
            }
            else if (village[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    DFS(0, 0);
    cout << ans << endl;
    return 0;
}