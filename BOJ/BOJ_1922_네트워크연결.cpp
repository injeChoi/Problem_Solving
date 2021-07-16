#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, ans;
vector<pii> graph[1001];
bool visited[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b}); // 가중치에 대해 minHeap을 유지하기 위해 weight를 first로 세팅 
        graph[b].push_back({w, a});
    }

    pq.push({0, 1});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;
            ans += weight;
            for (pii iter : graph[node]) {
                int nextWeight = iter.first;
                int nextNode = iter.second;
                if (!visited[nextNode]) {
                    pq.push({nextWeight, nextNode});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}