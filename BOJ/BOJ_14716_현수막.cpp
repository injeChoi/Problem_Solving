#include <bits/stdc++.h>
using namespace std;

int R, C, cnt;
int Map[250][250];
int visited[250][250];
// 상 하 좌 우 좌상 좌하 우상 우하
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int r, int c) {
    visited[r][c] = 1;

    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc] == 1) 
                continue;
            
            if (Map[nr][nc] == 1) 
                DFS(nr, nc);
        }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> Map[i][j];
    
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            if (Map[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                DFS(i, j);
            }

    cout << cnt << endl;
    return 0;
}

