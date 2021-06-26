#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, map[64][64];
bool check[64][64];
const int dx[] = {1, 0}, dy[] = {0, 1};

void BFS() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    check[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second; 
        q.pop();
        int k = map[x][y];

        if (x == n-1 && y == n-1) {
            cout << "HaruHaru" << endl;
            return;
        }
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i] * k;
            int ny = y + dy[i] * k;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) 
                continue;

            if (!check[nx][ny]) {
                q.push(make_pair(nx, ny));
                check[nx][ny] = true;
            }
        }
    }
    cout << "Hing" << endl;
}

int main() {
    init();
    cin >> n;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> map[i][j];
       
    BFS();
    return 0;
} 
