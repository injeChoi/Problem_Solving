#include <bits/stdc++.h>
using namespace std;

int R, C;
char arr[51][51];
int water[51][51];
int visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > wq;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void water_BFS() {
    while(!wq.empty()) {
        int x = wq.front().first;
        int y = wq.front().second;
        wq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (water[nx][ny] == 0 && arr[nx][ny] == '.') {
                water[nx][ny] = water[x][y] + 1;
                wq.push({nx, ny});
            }
        }
    }
}

void BFS(int r, int c) {
    queue<pair<int, int> > q;
    q.push({r, c});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] != 0) 
                continue;
            
            if (visited[nx][ny] == 0 && (arr[nx][ny] == '.' || arr[nx][ny] == 'D')) {
                if (water[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
                else if (water[nx][ny] > visited[x][y] + 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') 
                wq.push({i, j});
        } 
    }
           
    water_BFS();
        
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            if (arr[i][j] == 'S') 
                BFS(i, j);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'D') {
                if (visited[i][j] != 0) 
                    cout << visited[i][j] << endl;
                
                else 
                    cout << "KAKTUS" << endl;
                
            }
        }
    }
    return 0;
}