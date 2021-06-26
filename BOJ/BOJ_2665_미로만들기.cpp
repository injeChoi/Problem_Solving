#include <bits/stdc++.h>
using namespace std;

int N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int arr[51][51];
int visited[51][51];

void BFS() {
    visited[0][0] = 0;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (arr[nx][ny] == 1) {
                    if (visited[nx][ny] > visited[x][y]) {
                        visited[nx][ny] = visited[x][y];
                        q.push({nx, ny});
                    }
                }
                else {
                    if (visited[nx][ny] > visited[x][y] + 1) {
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            scanf("%1d", &arr[i][j]);

    fill(&visited[0][0], &visited[N][N], 987654321);
    BFS();
    cout << visited[N-1][N-1] << endl;

    return 0;
}