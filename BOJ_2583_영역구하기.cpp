#include <bits/stdc++.h>
using namespace std;

int C, R, K;
int X1, Y1, X2, Y2, cnt;
int Map[101][101];
int visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int x, int y) {
    cnt++;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= C || ny >= R) 
            continue;
        
        if (Map[nx][ny] == 0 && visited[nx][ny] == false) 
            DFS(nx, ny);
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> C >> R >> K;

    while (K--) {
        cin >> Y1 >> X1 >> Y2 >> X2;

        for (int i = X1; i < X2; i++) {
            for (int j = Y1; j < Y2; j++) {
                Map[i][j] = 1;
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (Map[i][j] == 0 && visited[i][j] == false) {
                cnt = 0;
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }
    
    cout << v.size() << endl;

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << endl;

    return 0;
}
