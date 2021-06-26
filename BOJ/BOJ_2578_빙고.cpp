#include <bits/stdc++.h>
using namespace std;

int vec[5][5];
int num, cnt, ans;
bool bingo = false, again = true;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check() {
    cnt = 0;
    int chk = 0;
    for (int i = 0; i < 5; i++) {
        chk = 0;
        for (int j = 0; j < 5; j++) {
            if (vec[i][j] == 0) chk++;
            if (chk == 5) {
                cnt++; 
                if (cnt == 3) return true;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        chk = 0;
        for (int j = 0; j < 5; j++) {
            if (vec[j][i] == 0) chk++;
            if (chk == 5) {
                cnt++;
                if (cnt == 3) return true;
            } 
        }
    }

    chk = 0;
    for (int i = 0; i < 5; i++) {
        if (vec[i][i] == 0) chk++;
        if (chk == 5) {
            cnt++;
            if (cnt == 3) return true;
        }
    }

    chk = 0; 
    int idx = 4;
    for (int i = 0; i < 5; i++) {
        if (vec[idx--][i] == 0) chk++;
        if (chk == 5) {
            cnt++;
            if (cnt == 3) return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    init();

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) 
            cin >> vec[i][j];

    for (int k = 0; k < 25; k++) {
        cin >> num;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (again == true && num == vec[i][j]) {
                    vec[i][j] = 0;
                    bingo = check();
                    if (bingo) {
                        ans = k;
                        again = false;
                    }
                }
            }
        }
    }
    cout << ans+1 << endl;
    return 0;
}