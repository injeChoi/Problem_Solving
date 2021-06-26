#include <bits/stdc++.h>
using namespace std;

int R, C, cnt, remain, res;
int arr[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >=0 && ny >= 0 && nx < R && ny < C && !visited[nx][ny]) {
                if (arr[nx][ny] == 0) 
                    q.push({nx, ny});
                
                else if (arr[nx][ny] == 1)
                    arr[nx][ny] = 0;
                
                visited[nx][ny] = true;
            }
        }
        
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];

    while (1) {
        for (int i = 0; i < R; i++) 
            for (int j = 0; j < C; j++) 
                if (arr[i][j] == 1) 
                    remain++;
        
        if (remain == 0) break;
        else {
            cnt++;
            res = remain;
        }

        memset(visited, 0, sizeof(visited));
        remain = 0;

        BFS();
    }

    cout << cnt << endl << res << endl;
    return 0;
}