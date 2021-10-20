#include <bits/stdc++.h>
using namespace std;

int N;
char graph[6][6];
bool visited[6][6];
vector<int> result;
int dy[2] = {1, 0};
int dx[2] = {0, 1};

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int cal(deque<char> que) {
    string s = "";
    while (!que.empty()) {
        s += que.front();
        que.pop_front();
    }
    int num = s[0] - '0';
    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] == '+') {
            num += s[i+1] - '0';
        }
        else if (s[i] == '-') {
            num -= s[i+1] - '0';
        }
        else if (s[i] == '*') {
            num *= s[i+1] - '0';
        }
    }
    return num;
}

void DFS(int y, int x, deque<char> q) {
    visited[y][x] = true;

    if (y == N-1 && x == N-1) {
        result.push_back(cal(q));
        return;
    }
    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < N) {
            q.push_back(graph[ny][nx]);
            DFS(ny, nx, q);
            q.pop_back();
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    deque<char> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    q.push_back(graph[0][0]);
    DFS(0, 0, q);
    sort(result.begin(), result.end());
    cout << result.back() << ' ' << result.front() << '\n';
    return 0;
}