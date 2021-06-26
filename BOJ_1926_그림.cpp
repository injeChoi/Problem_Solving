#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C, MAX, drawing;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int r, int c) {
    int cnt = 1;
    visited[r][c] = true;
    queue<pair<int, int> > q;
    q.push({r, c});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visited[nx][ny] && arr[nx][ny] == 1) {
                cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    MAX = max(cnt, MAX);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];

    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            if (arr[i][j] == 1 && !visited[i][j]) {
                drawing++;
                BFS(i, j);
            }
            
    cout << drawing << endl << MAX << endl;
    return 0;
}