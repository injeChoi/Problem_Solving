#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int R, C, r, c;
    int tmp1 = 0, tmp2 = 0, length = 0;
    cin >> R >> C;
    char **Map = new char*[R];
    for (int i = 0; i < R; i++) 
        Map[i] = new char[C];
    
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            cin >> Map[i][j];
        
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            if (Map[i][j] == '#') {
                r = i;
                c = j;
                i = R;
                break;
            }
    
    for (int i = r; i < R; i++) {
        if (Map[i][c] == '#') 
            tmp1++;
        else 
            break;
    }
    for (int i = c; i < C; i++) {
        if (Map[r][i] == '#') 
            tmp2++;
        else   
            break;
    }
    length = max(tmp1, tmp2);

    for (int i = c; i < c + length; i++) 
        if (Map[r][i] == '.') 
            cout << "UP" << endl;
    
    for (int i = c; i < c + length; i++) 
        if (Map[r + length-1][i] == '.') 
            cout << "DOWN" << endl;
    
    for (int i = r; i < r + length; i++) 
        if (Map[i][c] == '.') 
            cout << "LEFT" << endl;
    
    for (int i = r; i < r + length; i++) 
        if (Map[i][c + length-1] == '.') 
            cout << "RIGHT" << endl;

    for (int i = 0; i < R; i++) 
        delete[] Map[i];
    delete[] Map;

    return 0;
}