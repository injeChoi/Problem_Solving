#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<vector<bool> > visited(301, vector<bool>(301, 0));
vector<vector<int> > graph(301, vector<int>(301, 0));
int T, L;
int start_X, start_Y, dest_X, dest_Y;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int sx, int sy) {
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == dest_X && y == dest_Y) {   //destination과 동일하면 출력
            cout << graph[x][y] << endl;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < L && ny >= 0 && ny < L) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    graph[nx][ny] = graph[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    freopen("input.txt", "r", stdin);
    cin >> T;

    while(T--) {
        fill(visited.begin(), visited.end(), vector<bool>(301, 0)); //2차원 벡터 초기화
        fill(graph.begin(), graph.end(), vector<int>(301, 0));
        cin >> L;
        cin >> start_X >> start_Y;
        cin >> dest_X >> dest_Y;
        if (start_X == dest_X && start_Y == dest_Y)
            cout << 0 << endl;
        else
            BFS(start_X, start_Y);
    }

    return 0;
}
