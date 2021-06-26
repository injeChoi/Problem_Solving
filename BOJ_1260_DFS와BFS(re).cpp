#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<bool> > v(1001, vector<bool>(1001, 0));
vector<bool> visited(1001);
queue<int> q;

void DFS(int idx) {
    cout << idx << " ";

    for (int i = 1; i <= N; i++)
        if (v[idx][i] && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
}

void BFS(int idx) {
    q.push(idx);
    visited[idx] = true;

    while (!q.empty()) {
        cout << q.front() << " ";
        idx = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
            if (v[idx][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        v[from][to] = true;
        v[to][from] = true;
    }

    visited[V] = true;
    DFS(V);
    cout << endl;

    fill(visited.begin(), visited.end(), 0);
    BFS(V);
    cout << endl;

    return 0;
}
