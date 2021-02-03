#include <bits/stdc++.h>
using namespace std;

int a, b, N, M, p1, p2;
vector<int> adj[1001];
int counter[1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS() {
    queue<int> q;
    q.push(a);
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num == b) {
            cout << counter[num] << endl;
            return;
        }
        for (int i = 0; i < adj[num].size(); i++) {
            int look = adj[num][i];
            if (counter[look] == 0) {
                q.push(look);
                counter[look] = counter[num] + 1;
            }
        }
    }
    cout << "-1" << endl;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> a >> b;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }

    BFS();
    return 0;
}