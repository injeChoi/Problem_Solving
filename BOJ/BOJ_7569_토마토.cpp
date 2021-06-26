#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int day;
bool done = false;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int Map[101][101][101];
int isOne[101][101][101];
queue<tuple<int, int, int> > q;

void BFS() {
    while (!q.empty()) {
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();
        // tie(x, y, z) = q.front();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
            if (Map[nz][nx][ny] == 0 && !isOne[nz][nx][ny]) {
                q.push({nz, nx, ny});
                Map[nz][nx][ny] = Map[z][x][y] + 1;
                isOne[nz][nx][ny] = true;
            }
        }
    }
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) 
        for (int j = 0; j < N; j++) 
            for (int k = 0; k < M; k++) {
                cin >> Map[i][j][k];
                if (Map[i][j][k] == 0) done = true;
                else if (Map[i][j][k] == 1) {
                    q.push({i, j, k});
                    isOne[i][j][k] = true;
                } 
            }

    if (done == false) {
        cout << 0 << endl;
        return 0;
    }
    else BFS();

    for (int i = 0; i < H; i++) 
        for (int j = 0; j < N; j++) 
            for (int k = 0; k < M; k++) {
                if (Map[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                else if (day < Map[i][j][k]) {
                    day = Map[i][j][k];
                }
            }

    cout << day-1 << endl;
    return 0;
}