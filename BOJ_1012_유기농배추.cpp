#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 51

int M, N, K;
vector<vector<int> > graph(MAX, vector<int>(MAX));
bool visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int y, int x) {
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx >= 0 && ny >= 0 && nx < MAX && ny < MAX)
      if(graph[ny][nx] && !visited[ny][nx]) {
        visited[ny][nx] = 1;
        DFS(ny, nx);
      }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T; cin >> T;
  
  while (T--) {
    int cnt = 0;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
      int x, y; cin >> x >> y;
      graph[y][x] = 1;
    }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if(graph[i][j] && !visited[i][j]) {
          cnt++;
          DFS(i, j);
        }

    cout << cnt << "\n";

    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++)
        visited[i][j] = 0;

    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++)
        graph[i][j] = 0;
  }

  return 0;
}
