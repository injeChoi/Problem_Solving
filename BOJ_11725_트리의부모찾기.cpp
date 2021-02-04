#include <bits/stdc++.h>
using namespace std;

int N, p1, p2;
vector<int> v[100001];
int parent[100001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int child = v[cur][i];
            // 양 방향 tree 구조 이므로 이미 parent에서 child를 방문했으면 child에서는 parent 방문 못하게 막기
            if (parent[cur] == child) continue; 
            q.push(child);
            parent[child] = cur;
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        cin >> p1 >> p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }

    BFS();

    for (int i = 2; i <= N; i++) 
        cout << parent[i] << "\n";

    return 0;
}