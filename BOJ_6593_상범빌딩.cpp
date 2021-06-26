#include <bits/stdc++.h>
using namespace std;

int L, R, C;
const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};
char Map[31][31][31];
int Time[31][31][31];
int sx, sy, sz, ex, ey, ez;

struct location {
    int x, y, z;
};

void init() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    queue<location> q;
    q.push({sx, sy, sz}); // S = 시작 위치 세팅 

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if (x == ex && y == ey && z == ez) {
            cout << "Escaped in " << Time[x][y][z] << " minute(s)." << endl; // 현재 위치가 탈출구면 탈출
            return;
        }

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) {
                continue;
            }
            if (Time[nx][ny][nz] || Map[nx][ny][nz] == '#') {
                continue;
            }
            Time[nx][ny][nz] = Time[x][y][z] + 1;   // 원래 있던 위치보다 1분 추가 
            q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!" << endl; // 큐가 비었는데도 갇혀있다면 Trap
}

int main(int argc, char const *argv[]) {
    init();
    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) 
            break;
        
        memset(Time, 0, sizeof(Time));  // TC마다 몇분 걸렸는지에 대한 정보 초기화 
        
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> Map[i][j][k];

                    if (Map[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    else if (Map[i][j][k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        BFS();
    }
    return 0;
}