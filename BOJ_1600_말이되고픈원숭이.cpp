#include <bits/stdc++.h>
using namespace std;

int K, W, H;
int Map[201][201];
bool visited[201][201][31];
int hx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int BFS() {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push({{0, 0}, {0, 0}});

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int h = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (x == H-1 && y == W-1) return cnt;

        if (h < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (Map[nx][ny] == 0 && !visited[nx][ny][h+1]) {
                    visited[nx][ny][h+1] = true;
                    q.push({{nx, ny}, {h+1, cnt+1}});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (Map[nx][ny] == 0 && !visited[nx][ny][h]) {
                visited[nx][ny][h] = true;
                q.push({{nx, ny}, {h, cnt+1}});
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) 
            cin >> Map[i][j];

    cout << BFS() << endl;
    return 0;
}