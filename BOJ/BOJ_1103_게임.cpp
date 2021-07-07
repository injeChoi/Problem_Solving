#include <bits/stdc++.h>
using namespace std;

int N, M, ans, limit;
int maxCount[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char board[50][51];

void DFS(int y, int x, int cnt) {
    ans = max(ans, cnt);    // 많이 뛴 횟수 저장 
    if (ans > limit) {
        cout << -1 << endl;
        exit(0);
    }
    //예외처리
    if (y < 0 || y >= N || x < 0 || x >= M || board[y][x] == -1) {
        return;
    }
    // 어느 지점에 온 점프 횟수가 원래 횟수보다 적거나 같으면 다시 할 필요 없음 
    if (cnt <= maxCount[y][x]) {
      return;  
    }
    maxCount[y][x] = cnt;

    int mul = board[y][x];
    for (int i = 0; i < 4; i++) {
        DFS(y + dy[i] * mul, x + dx[i] * mul, cnt+1);
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    limit = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxCount[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'H') {
                board[i][j] = -1;
            }
            else {
                board[i][j] -= '0';
            }
        }
    }
    DFS(0, 0, 0);
    cout << ans << endl;
    return 0;
}