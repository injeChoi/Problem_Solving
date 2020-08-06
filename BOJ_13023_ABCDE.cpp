#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[2001];
vector<bool> visited(2001);
int N, M;
bool check;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int idx, int cnt) {
    if (cnt == 4) {
        check = true;
        return;
    }
    visited[idx] = true;
    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];
        if (!visited[next]) 
            DFS(next, cnt + 1);
        if (check == true) 
            return;
    }
    visited[idx] = false;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to; 
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), 0);
        DFS(i, 0);
        if (check) 
            break;
    }
    if (check) 
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
