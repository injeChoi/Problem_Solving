#include <bits/stdc++.h>
using namespace std;

int N, M;
bool flag;
int board[1001][1001];
bool visited[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] == 0 && !(visited[ny][nx])) {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        if (board[0][i] == 0 && !(visited[0][i])) {
            DFS(0, i);
        }
    }
    for (int i = 0; i < M; i++) {
        if (visited[N-1][i] == 1) {
            flag = true;
            break;
        }
    }
    flag == true ? cout << "YES" << endl : cout << "NO" << endl; 
    return 0;
}