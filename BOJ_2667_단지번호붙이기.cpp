#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 26

int N;
bool visited[MAX][MAX];
int graph[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int house_num[MAX * MAX] = {0, };
int cnt = 0;

void DFS(int y, int x) {
  visited[y][x] = true;
  house_num[cnt]++;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny >= 0 && nx >= 0 && ny < MAX && nx < MAX)
      if(graph[ny][nx] && !visited[ny][nx])
        DFS(ny, nx);
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%1d", &graph[i][j]);
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if(graph[i][j] && !visited[i][j]) {
        cnt++;
        DFS(i, j);
      }

  sort(house_num + 1, house_num + cnt+1);

  cout << cnt << "\n";
  for (int i = 1; i <= cnt; i++)
    cout << house_num[i] << "\n";

  return 0;
}
