#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<vector<int> > graph(1001, vector<int>(1001, 0));
vector<vector<bool> > visited(1001, vector<bool>(1001, 0));
queue<pair<int, int> > q;
int N, M, day;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    while (!q.empty()) {
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && 0 <= ny && nx < M && ny < N && graph[nx][ny] == 0) {
                graph[nx][ny] = graph[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) 
                q.push(make_pair(i, j)); 
        }
    }
    
    BFS();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // 익지않은 토마토(0)가 존재할 경우
            if (graph[i][j] == 0) { 
                printf("-1\n");
                return 0;
            }
            // 토마토는 다 익었는데, 얼마만에 익었는지?
            if (day < graph[i][j]) {
                day = graph[i][j];
            }
        }
    }
    printf("%d\n", day-1);

    return 0;
}
