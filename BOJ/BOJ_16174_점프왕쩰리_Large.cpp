#include <bits/stdc++.h>
using namespace std;

int N;
int graph[65][65];
bool visited[65][65];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int y, int x) {
    visited[y][x] = true;
    if (graph[y][x] == -1) {
        return;
    }
    int ny = y + graph[y][x];
    int nx = x + graph[y][x];
    if (0 <= ny && ny < N && !visited[ny][x]) {
        DFS(ny, x);
    }
    if (0 <= nx && nx < N && !visited[y][nx]) {
        DFS(y, nx);
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    DFS(0, 0);
    if (visited[N-1][N-1]) {
        cout << "HaruHaru" << '\n';
    }
    else {
        cout << "Hing" << '\n';
    }
    return 0;
}