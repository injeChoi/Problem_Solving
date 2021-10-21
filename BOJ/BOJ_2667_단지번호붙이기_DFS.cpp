#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int graph[26][26];
bool visited[26][26];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> result;

void DFS(int y, int x) {
    result[cnt]++;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < N && graph[ny][nx] && !visited[ny][nx]) {
            DFS(ny, nx);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] && !visited[i][j]) {
                result.push_back(0);
                DFS(i, j);
                cnt++;
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int iter : result) {
        cout << iter << '\n';
    }
    return 0;
}