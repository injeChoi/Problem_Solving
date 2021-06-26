#include <bits/stdc++.h>
using namespace std;

int R, C, result;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char arr[51][51];
int visited[51][51];
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int r, int c) {
    visited[r][c] = 0;
    queue<pair<int, int> > q;
    q.push({r, c});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] != -1 || arr[nx][ny] != 'L') 
                continue;
            
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
            v.push_back(visited[nx][ny]);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    memset(visited, -1, sizeof(visited));

    cin >> R >> C;
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];

    v.push_back(0);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'L') {
                BFS(i, j);
                memset(visited, -1, sizeof(visited));
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.back() << endl;

    return 0;
}