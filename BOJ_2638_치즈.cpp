#include <bits/stdc++.h>
using namespace std;

int N, M, num, remain, cnt;
pair<int, int> arr[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    visited[0][0] = true;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny]) {
                if (arr[nx][ny].first == 1) {
                    arr[nx][ny].second++;
                    if (arr[nx][ny].second >= 2) {
                        arr[nx][ny].first = 0;
                        visited[nx][ny] = true;
                    }
                }
                else if (arr[nx][ny].first == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) {
            cin >> num;
            arr[i][j] = make_pair(num, 0);
        }
    
    while (1) {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) 
                if (arr[i][j].first == 1) 
                    remain++;

        if (remain == 0) 
            break;
        else 
            cnt++;

        memset(visited, 0, sizeof(visited));
        remain = 0;
        BFS();

        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) 
                arr[i][j].second = 0;
    }
    cout << cnt << endl;
    return 0;
}