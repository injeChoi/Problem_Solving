#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int N, M, cnt = 0;

void DFS(int idx) {
  visited[idx] = 1;

  for (int i = 0; i < adj[idx].size(); i++) {
    int next = adj[idx][i];

    if(!visited[next]) {
      cnt++;
      DFS(next);
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  DFS(1);
  cout << cnt << "\n";

  return 0;
}
