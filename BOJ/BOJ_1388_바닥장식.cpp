#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
char graph[101][101];
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int y, int x, char c) {
    visited[y][x] = true;
    if (c == '|') {
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M && graph[ny][nx] == c && !(visited[ny][nx])) {
                DFS(ny, nx, c);
            }
        }
    }
    else if (c == '-') {
        for (int i = 2; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M && graph[ny][nx] == c && !(visited[ny][nx])) {
                DFS(ny, nx, c);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!(visited[i][j])) {
                cnt++;
                DFS(i, j, graph[i][j]);
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}