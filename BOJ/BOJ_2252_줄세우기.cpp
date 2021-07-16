// 위상 정렬 
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[32001];
int in[32001];
queue<int> q;   // 순서대로 출력할 vertex 번호 

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);  // 나보다 큰 놈 인접리스트로 저장해두기 
        in[b]++;            // 진입차수 기록하기 
    }
    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {   // 진입차수가 0이면 큐에 추가 
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';   // 진입차수가 0이게 된 vertex 출력 
        for (int node : graph[v]) {
            if ((--in[node]) == 0) {    // 진입차수가 0이 된 vertex와 관련된 edge제거 하는 역할 
                q.push(node);           
            }
        }
    }
    return 0;
}