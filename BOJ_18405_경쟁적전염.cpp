#include<bits/stdc++.h>
using namespace std;
 
int n, k;
int Map[201][201];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<int, int> > v[1001];
bool visited[201][201];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void BFS(int s, int ey, int ex)
{
    queue<tuple<int, int, int> > q;
 
    for (int i = 1; i <= k; i++) {
        if (!v[i].empty()) {
            for (auto p : v[i]) {
                q.push({ i, p.first, p.second });
                visited[p.first][p.second] = true;
            }
        }
    }
 
    while (!q.empty() && s--)
    {
        int qs = q.size();
 
        while (qs--)
        {
            int num, r, c;
            tie(num, r, c) = q.front();
            q.pop();
 
            for (int i = 0; i < 4; i++) {
                int y = r + dy[i];
                int x = c + dx[i];
 
                if (y < 0 || y >= n || x < 0 || x >= n || visited[y][x]) 
                    continue;
                
                Map[y][x] = num;
                visited[y][x] = true;
                q.push({ num, y, x });
            }
        }
    }
    cout <<  Map[ey][ex] << endl;
}

int main()
{
    init();
    cin >> n >> k;
 
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
 
            if (Map[i][j]) {
                v[Map[i][j]].push_back({ i, j });
            }
        }
    }
 
    int s, y, x;
    cin >> s >> y >> x;
    BFS(s, y - 1, x - 1);
 
    return 0;
}
