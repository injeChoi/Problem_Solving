#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 101

int N, M;
int user[MAX][MAX];
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
int connect[MAX];
bool visited[MAX];

void BFS(int idx) {
  visited[idx] = true;
  queue<int> q;
  q.push(idx);

  while(!q.empty()) {
    int num = q.front();
    q.pop();

    for (int i = 1; i <= N; i++)
      if(user[num][i] && !visited[i]) {
        connect[i] = connect[num] + 1;
        visited[i] = true;
        q.push(i);
      }
  }

  int sum = 0;
  for (int i = 1; i <= N; i++)
    sum += connect[i];

  pq.push(make_pair(sum, idx));
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;
    user[from][to] = 1;
    user[to][from] = 1;
  }

  for (int i = 1; i <= N; i++) {
    BFS(i);
    memset(connect, 0, sizeof(connect));
    memset(visited, 0, sizeof(visited));
  }

  cout << pq.top().second << "\n";

  return 0;
}
