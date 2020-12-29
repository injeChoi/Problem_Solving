#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int x, int y, char **Map, bool **visited, int row, int col) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= row || ny >= col || visited[nx][ny]) 
            continue;
        if (Map[nx][ny] == '#') {
            cnt++;
            DFS(nx, ny, Map, visited, row, col);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    int N; cin >> N;
    int col = N / 5;
    int row = N / col;
    char **Map = new char*[row];
    for (int i = 0; i < row; i++) 
        Map[i] = new char[col];

    bool **visited = new bool*[row];
    for (int i = 0; i < row; i++) 
        visited[i] = new bool[col];
    
    for (int i = 0; i < row; i++) 
        memset(visited[i], 0, sizeof(bool) * col);
    
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) 
            cin >> Map[i][j];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cnt = 1;
            if (Map[i][j] == '#' && visited[i][j] == false) {
                DFS(i, j, Map, visited, row, col);
                
                if (cnt == 5) 
                    cout << 1;
                else if (cnt == 7) 
                    cout << 7;
                else if (cnt == 9) 
                    cout << 4;
                else if (cnt == 11) {
                    if (Map[i+1][j+2] == '.')
                        cout << 5;
                    else if (Map[i+3][j] == '.')
                        cout << 3;
                    else
                        cout << 2;
                }
                else if (cnt == 12) {
                    if (Map[i+2][j+1] == '.')
                        cout << 0;
                    else if (Map[i+1][j+2] == '.')
                        cout << 6;
                    else 
                        cout << 9;
                }
                else if (cnt == 13)
                    cout << 8;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < row; i++) 
        delete[] Map[i];
    delete[] Map;

    for (int i = 0; i < row; i++) 
        delete[] visited[i];
    delete[] visited;
        
    return 0;
}