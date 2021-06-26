#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 501

vector<int> adj[MAX];
bool visited[MAX];
int cnt = 0;

void DFS(int idx) {
  for (int i = 0; i < adj[idx].size(); i++) {
    int next = adj[idx][i];
    visited[next] = true;
  }

  if (idx == 1)
    for (int i = 0; i < adj[idx].size(); i++) {
      int next = adj[idx][i];
      DFS(next);
    }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int M; cin >> M;

  for (int i = 0; i < M; i++) {
    int from, to; cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  DFS(1);

  for (int i = 2; i <= N; i++)
    if(visited[i])
      cnt++;

  cout << cnt << "\n";

  return 0;
}
