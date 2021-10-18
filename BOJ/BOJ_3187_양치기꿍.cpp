#include <bits/stdc++.h>
using namespace std;

int R, C;
char graph[251][251];
bool visited[251][251];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int sheep, wolf, s, w;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int y, int x) {
    if (graph[y][x] == 'k') {
        s++;
    }
    else if (graph[y][x] == 'v') {
        w++;
    }
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < R && 0 <= nx && nx < C && graph[ny][nx] != '#' && !(visited[ny][nx])) {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (graph[i][j] != '#' && !(visited[i][j])) {
                s = 0; w = 0;
                DFS(i, j);
                if (s > w) {
                    sheep += s;
                }
                else {
                    wolf += w;
                }
            }
        }
    }
    cout << sheep << ' ' << wolf << '\n';
    return 0;
}