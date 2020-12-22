#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int H, W;
int cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> H >> W;
    char map[H][W];
    int newMap[H][W];
    fill(newMap[0], newMap[0] + (H * W), -1);
    
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) 
            cin >> map[i][j];
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cnt = 0;
            int tmp = j;
            if (map[i][j] == 'c') {
                newMap[i][j] = 0;
                while (tmp + 1 < W && map[i][++tmp] != 'c') 
                    newMap[i][tmp] = ++cnt;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) 
            cout << newMap[i][j] << " ";
        cout << endl;
    }
    return 0;
}
