#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[51][51];
vector<vector<int> > graph(51);
int dh[8] = {0, 0, 1, -1, 1 ,1, -1, -1};
int dw[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int w, h, cnt;

void DFS(int h_, int w_) {
  visited[h][w] = true;

  for (int i = 0; i < 8; i++) {
    int nh = h_ + dh[i];
    int nw = w_ + dw[i];

    if(nh >= 0 && nw >= 0 && nh < h && nw < w)
      if(graph[nh][nw] && !visited[nh][nw]) {
        visited[nh][nw] = true;
        DFS(nh, nw);
      }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (1) {
    cnt = 0;
    cin >> w >> h;

    if(w == 0 && h == 0)
      break;

    else {
      for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
          int input; cin >> input;
          graph[i].push_back(input);
        }

      for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
          if(graph[i][j] && !visited[i][j]) {
            DFS(i, j);
            cnt++;
          }
        }
      }
    }
    cout << cnt << "\n";

    for (int i = 0; i < graph.size(); i++)
      graph[i].clear();

    for (int i = 0; i < 51; i++)
      for (int j = 0; j < 51; j++)
        visited[i][j] = 0;
  }

  return 0;
}
