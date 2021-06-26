#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C;
int cnt, minR = 100, maxR, minC = 100, maxC;
char c;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;
    char currentMap[12][12];
    char futureMap[12][12];
    fill(currentMap[0], currentMap[0]+144, '.');

    for (int i = 1; i <= R; i++) 
        for (int j = 1; j <= C; j++) {
            cin >> c;
            if (c == 'X') 
                currentMap[i][j] = c;
        }
    memcpy(futureMap, currentMap, sizeof(futureMap));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cnt = 0;
            if (currentMap[i][j] == 'X') {
                if (currentMap[i+1][j] == '.') 
                    cnt++;

                if (currentMap[i-1][j] == '.') 
                    cnt++;

                if (currentMap[i][j+1] == '.') 
                    cnt++;
                
                if (currentMap[i][j-1] == '.') 
                    cnt++;
            }
            if (cnt > 2) 
                futureMap[i][j] = '.';
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (futureMap[i][j] == 'X') {
               minC = min(minC, j);
               maxC = max(maxC, j);
               minR = min(minR, i);
               maxR = max(maxR, i);
            }
        }
    }
    
    for (int i = minR; i <= maxR; i++) {
        for (int j = minC; j <= maxC; j++)
            cout << futureMap[i][j] << "";
        cout << endl;
    }

    return 0;
}
