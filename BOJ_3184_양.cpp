#include <bits/stdc++.h>
using namespace std;

int R, C, sheep, wolf, totalSheep, totalWolf;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char arr[251][251];
bool visited[251][251];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int r, int c) {
    visited[r][c] = true;
    queue<pair<int, int> > q;
    q.push({r, c});

    if (arr[r][c] == 'o') sheep++;
    else if (arr[r][c] == 'v') wolf++;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] || arr[nx][ny] == '#')
                continue;

            if (arr[nx][ny] == 'o') sheep++;
            else if (arr[nx][ny] == 'v') wolf++;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;

    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'o') totalSheep++;
            else if (arr[i][j] == 'v') totalWolf++;
        }
    }
        
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((arr[i][j] == 'o' || arr[i][j] == 'v') && !visited[i][j]) {
                BFS(i, j);
                if (sheep > wolf) totalWolf -= wolf;
                else totalSheep -= sheep;
                sheep = 0; wolf = 0;
            }
        }
    }

    cout << totalSheep << " " << totalWolf << endl;
    return 0;
}