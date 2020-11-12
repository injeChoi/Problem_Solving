#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char arr[10][4];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    string s; cin >> s;
    int cnt = 0;
    
    arr[2][0] = 'A'; arr[2][1] = 'B'; arr[2][2] = 'C';
    arr[3][0] = 'D'; arr[3][1] = 'E'; arr[3][2] = 'F';
    arr[4][0] = 'G'; arr[4][1] = 'H'; arr[4][2] = 'I';
    arr[5][0] = 'J'; arr[5][1] = 'K'; arr[5][2] = 'L';
    arr[6][0] = 'M'; arr[6][1] = 'N'; arr[6][2] = 'O';
    arr[7][0] = 'P'; arr[7][1] = 'Q'; arr[7][2] = 'R'; arr[7][3] = 'S';
    arr[8][0] = 'T'; arr[8][1] = 'U'; arr[8][2] = 'V';
    arr[9][0] = 'W'; arr[9][1] = 'X'; arr[9][2] = 'Y'; arr[9][3] = 'Z';
    
    for (int i = 0; i < s.length(); i++) 
        for (int j = 2; j <= 9; j++) 
            for (int k = 0; k < sizeof(arr[j]); k++) 
                if (s[i] == arr[j][k]) 
                    cnt += j + 1;
                    
    cout << cnt << endl;

    return 0;
}

