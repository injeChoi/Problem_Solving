#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[101][101];
bool visited[101][101];
int R, C, K, k1, k2, biggest, tmp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int i, int j) {
    queue<pair<int, int> > q;
    q.push({i, j});
    visited[i][j] = true;
    tmp = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= R && ny > 0 && ny <= C && !visited[nx][ny]) {
                if (arr[nx][ny] == true) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    tmp++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C >> K;

    for (int i = 0; i < K; i++) {
        cin >> k1 >> k2;
        arr[k1][k2] = 1;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] == true) {
                BFS(i, j);
                biggest = max(biggest, tmp);
            }
        }
    }

    cout << biggest << endl;

    return 0;
}