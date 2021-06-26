#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool arr[101][101];
int check[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int BFS() {
  int x = 0;
  int y = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  check[x][y] = 1;

  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
        if(!check[nx][ny] && arr[nx][ny]) {
          check[nx][ny] = check[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  return check[N-1][M-1];
}

int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  // printf, scanf와 위 문장을 혼용해서는 안 된다.

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      int idx; scanf("%1d", &idx);

      if(idx == 1)
        arr[i][j] = true;
    }

  printf("%d\n", BFS());

  return 0;
}
