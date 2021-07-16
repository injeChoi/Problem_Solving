#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 987654321

int V, E, start;
vector<pii> a[300001];
int d[300001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Dijkstra(int start) {
    d[start] = 0;   // 나 자신과의 거리는 0 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int distance = pq.top().first; // 현재 노드로 오는 최소 거리 
        int cur = pq.top().second;   // 현재 노드
        pq.pop();
        if (d[cur] < distance) {    // 최단 거리가 아닌 경우 스킵 
            continue;
        }
        for (pii iter : a[cur]) {
            int nextDistance = distance + iter.first;  // 새로 계산한 다음 노드로 가는 비용 
            int nextVertex = iter.second;    // 다음 노드

            if (nextDistance < d[nextVertex]) { // 새롭게 구한 다음 노드로 이동하는 거리가 원래 거리보다 작으면 
                d[nextVertex] = nextDistance;   // 지금까지만 따져봤을 때 새로운 노드로 가는 최소 비용은 이번에 구한 값이다 
                pq.push({nextDistance, nextVertex});// 갱신한 값을 큐에 다시 넣기 (또 새로운 최소 값이 나올 수도 있으니까)
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> V >> E >> start;
    for (int i = 0; i <= V; i++) {
        d[i] = INF;
    }
    for (int i = 0; i < E; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        a[u].push_back({w, v});
    }

    Dijkstra(start);

    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << d[i] << '\n';
        }
    }
    return 0;
}