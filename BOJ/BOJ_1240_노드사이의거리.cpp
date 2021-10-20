#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<pii> tree[1001];
bool visited[1001];
int dist[1001][1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int s, int e, int d) {
    dist[s][e] = d;
    for (int i = 0; i < tree[e].size(); i++) {
        int node = tree[e][i].first;
        int cost = tree[e][i].second;
        if (!visited[node]) {
            visited[node] = true;
            DFS(s, node, d + cost);
            visited[node] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N-1; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        tree[s].push_back({e, d});
        tree[e].push_back({s, d});
    }
    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        DFS(i, i, 0);
        visited[i] = false;
    }
    for (int i = 0; i < M; i++) {
        int s, e; 
        cin >> s >> e;
        cout << dist[s][e] << '\n';
    }
    return 0;
}