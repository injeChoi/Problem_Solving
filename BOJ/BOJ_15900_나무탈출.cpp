#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> tree[500001];
bool visited[500001];
int total;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int s, int depth) {
    if (tree[s].size() == 1 && s != 1) {
        if (depth % 2 == 1) {
            total++;
        }
        return;
    }
    for (int i = 0; i < tree[s].size(); i++) {
        if (!visited[s]) {
            visited[s] = true;
            DFS(tree[s][i], depth+1);
            visited[s] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    DFS(1, 0);
    if (total % 2 == 1) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
    return 0;
}