#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M, ans;
int graph[501][501];
int path[501];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Floyd() {
    for (int k = 1; k <= N; k++) 
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            i == j ? graph[i][j] = 0 : graph[i][j] = INF;
        }
    }
    for (int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        graph[a][b] = 1;
    }
    Floyd();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && graph[i][j] < INF) {
                path[i]++;
                path[j]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (path[i] == N-1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}