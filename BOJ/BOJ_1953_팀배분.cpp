#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> tree[101];
int visited[101];
vector<int> blue, white;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int e, int team) {
    visited[e] = team;
    for (int i = 0; i < tree[e].size(); i++) {
        int next = tree[e][i];
        if (!visited[next]) {
            DFS(next, -team);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int p; cin >> p;
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i, 1);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1) {
            blue.push_back(i);
        }
        else if (visited[i] == -1) {
            white.push_back(i);
        }
    }
    sort(blue.begin(), blue.end());
    sort(white.begin(), white.end());

    cout << blue.size() << '\n';
    for (int i = 0; i < blue.size(); i++) {
        cout << blue[i] << ' ';
    }
    cout << '\n';
    cout << white.size() << '\n';
    for (int i = 0; i < white.size(); i++) {
        cout << white[i] << ' ';
    }
    cout << '\n';
    return 0;
}