#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

int N, M;
int p1, p2;
vector<int> visited(MAX);
vector<int> chon[MAX];


int BFS() {
  queue<int> q;
  q.push(p1);

  while(!q.empty()) {
    int num = q.front();
    q.pop();

    if (num == p2)
      return visited[p2];

    for (int i = 0; i < chon[num].size(); i++) {
      int next = chon[num][i];

      if(!visited[next]) {
        visited[next] = visited[num] + 1;
        q.push(next);
      }
    }
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> p1 >> p2;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int asc, des; cin >> asc >> des;
    chon[asc].push_back(des);
    chon[des].push_back(asc);
  }

  cout << BFS() << "\n";

  return 0;
}
