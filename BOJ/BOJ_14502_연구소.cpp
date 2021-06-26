#include <bits/stdc++.h>
using namespace std;

int N, M, safeArea;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int> > arr(9, vector<int>(9, 0));
vector<vector<int> > tmp(9, vector<int>(9, 0));

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    vector<vector<int> > newWall(9, vector<int>(9, 0));
    queue<pair<int, int> > q;

    newWall.assign(tmp.begin(), tmp.end());

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (newWall[i][j] == 2) 
                q.push({i, j}); 

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (newWall[nx][ny] == 0) {
                    newWall[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    int blank = 0;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (newWall[i][j] == 0)
                blank++;

    safeArea = max(safeArea, blank);
}

/*
 * DFS 방식으로 돌아가는 함수
 * main 함수에서 arr 벡터에서 0인 위치 (A)를 찾으면 벽을 세우기 시작
 * 3번 째 벽을 세웠을 때 BFS 함수 실행
 * BFS 함수 실행 후 3번 째 벽을 허문다
 * 새로운 0을 찾아 벽을 세우고 다시 BFS함수 실행
 * A에서 더 이상 새로운 위치에 벽을 세울 수 없으면 다음 0을 찾고 반복 
 */
void makeWall(int cnt) {
    if (cnt == 3) {
        BFS();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                makeWall(cnt+1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                tmp.assign(arr.begin(), arr.end());
                tmp[i][j] = 1;
                makeWall(1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << safeArea << endl;
    return 0;
}