#include <bits/stdc++.h>
using namespace std;

int T, H, W, cnt;
char graph[101][101];
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x+ dx[i];
        if (0 <= ny && ny < H && 0 <= nx && nx < W && graph[ny][nx] == '#' && !visited[ny][nx]) {
            DFS(ny, nx);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;
    while(T--) {
        cin >> H >> W;
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> graph[i][j];
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (graph[i][j] == '#' && !visited[i][j]) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}