#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, shark = 2, eat, sec, MIN = 987654321;
int board[21][21];
int check[21][21];
bool visited[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> v;
bool flag = true;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const pii &a, const pii &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void BFS(int _y, int _x) {
    int edible = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{_y, _x}, 1});

    while (!q.empty()) { 
        int y = q.front().first.first;
        int x = q.front().first.second;
        int t = q.front().second;
        q.pop();
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < N && !visited[ny][nx]) {
                if (board[ny][nx] == 0 || board[ny][nx] == shark) {  // 크기가 빈칸이거나 같으면 지나가면서 방문 표기  
                    q.push({{ny, nx}, t+1});
                    visited[ny][nx] = true;
                }
                else if (0 < board[ny][nx] && board[ny][nx] < shark) {   // 크기가 작으면 잡아먹기 
                    edible++;
                    check[ny][nx] = t;                                   // 먹으러 가는데 걸리는 시간 
                    visited[ny][nx] = true;
                }
            }
        }
    }
    if (edible == 0) {  // 잡아먹을 수 있는 애가 없으면 스톱 
        flag = false;
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check[i][j] != 0 && check[i][j] < MIN) {
                MIN = check[i][j];
                v.clear();
                v.push_back({i, j});
            }
            else if (check[i][j] != 0 && check[i][j] == MIN) {
                v.push_back({i, j});
            }
        }
    }
    if (v.size() > 1) {
        sort(v.begin(), v.end(), cmp);
    }
    board[v[0].first][v[0].second] = 9;
    eat++;
    sec += check[v[0].first][v[0].second];
}   

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    while (flag) {
        MIN = 987654321;
        v.clear();
        memset(visited, 0, sizeof(visited));
        memset(check, 0, sizeof(check));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 9) {
                    BFS(i, j);
                    board[i][j] = 0;
                    i = N; j = N;
                }
            }
        }
        if (eat == shark) {
            shark++;
            eat = 0;
        }
    }
    cout << sec << endl;
    return 0;
}