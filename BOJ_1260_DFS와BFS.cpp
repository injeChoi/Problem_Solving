#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj(1001, vector<int>(1001));
queue<int> q;
bool visited[1001];
int N, M, V;

void DFS(int idx) {
  cout << idx << " ";

  for (int i = 1; i <= N; i++) {
    if(adj[idx][i] && !visited[i]) {
      visited[i] = 1;
      DFS(i);
    }
  }
}

void BFS(int idx) {
  q.push(idx);
  visited[idx] = 1;

  while(!q.empty()) {
    idx = q.front();
    q.pop();
    cout << idx << " ";

    for (int i = 1; i <= N; i++) {
      if(adj[idx][i] && !visited[i]) {
        visited[i] = 1;
        q.push(i);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    adj[from][to] = 1;
    adj[to][from] = 1;
  }

  visited[V] = 1;
  DFS(V);
  cout << "\n";

  for (int i = 1; i <= 1000; i++) 
    visited[i] = 0;

  BFS(V);
  cout << "\n";

  return 0;
}
