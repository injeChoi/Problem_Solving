#include <bits/stdc++.h>
using namespace std;

int N, cnt_1, cnt_2;
char arr[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS_1() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] == arr[x][y] && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

void BFS_2() {
    int sx = q.front().first;
    int sy = q.front().second;

    if (arr[sx][sy] == 'B') {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (arr[nx][ny] == arr[x][y] && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    else {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if ((arr[nx][ny] == 'R' || arr[nx][ny] == 'G') && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}


int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                q.push({i, j});
                BFS_1();
                cnt_1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                q.push({i, j});
                BFS_2();
                cnt_2++;
            }
        }
    }

    cout << cnt_1 << endl;
    cout << cnt_2 << endl;
    return 0;
}