#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, cnt = 1, ans;
int BY, BX;
string board[11];
bool visited[11][11];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int BFS(int y, int x) {
    queue<pii> q, bq;;
    q.push({y, x});
    bq.push({BY, BX});
    visited[y][x] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int by = bq.front().first;
        int bx = bq.front().second;
        q.pop();
        bq.pop();

        for (int i = 0; i < 4; i++) {       // 기울이기 가능한 방향은 총 4개 
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nby = by;
            int nbx = bx;
            if (board[nby + dy[i]][nbx + dx[i]] == '.') {
                nby = by + dy[i];
                nbx = bx + dx[i];
            }
            if (visited[ny][nx] || (ny == nby && nx == nbx)) {
                continue;
            }
            while (board[ny][nx] != '#') {  // 기울인 방향으로 쭉 굴러가기 
                visited[ny][nx] = true;
                // if (board[nby][nbx] == 'O') {
                //     return -1;
                // }
                if (board[ny][nx] == 'O') { // 굴러가다가 구멍을 만나면 끝 
                    return cnt;
                }
                ny = ny + dy[i];            // 굴러가는 다음 위치 
                nx = nx + dx[i];
                if (board[nby + dy[i]][nbx + dx[i]] != '#') {
                    nby = nby + dy[i];          
                    nbx = nbx + dx[i];
                }

                if (board[ny][nx] == '#') { // 벽을 만나면 기울이기 종료, 구슬 위치를 큐에 넣음 
                    q.push({ny - dy[i], nx - dx[i]});
                    bq.push({nby, nbx});
                    if (cnt > 10) {         // cnt가 10회 이상이면 강제 종료 
                        return -1;
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'B') {
                BY = i;
                BX = j;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') {
                ans = BFS(i, j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}