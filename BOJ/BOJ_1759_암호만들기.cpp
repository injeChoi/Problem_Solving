#include <bits/stdc++.h>
using namespace std;

int L, C;

bool check(vector<char> &ans) {
    int mo = 0, ja = 0;
    bool isMo[128] = {0};
    isMo['a'-'a'] = true;
    isMo['e'-'a'] = true;
    isMo['i'-'a'] = true;
    isMo['o'-'a'] = true;
    isMo['u'-'a'] = true;

    for (int i = 0; i < L; i++) {
        if (isMo[ans[i]-'a']) {
            mo++;
        }
        else {
            ja++;
        }
    }
    return mo >= 1 && ja >= 2;
}

void recu(vector<char> &alpha, vector<char> &answer, int where, int from) {
    // 탈출 조건
    if (where == L) {
        if (check(answer)) {
            for (int i = 0; i < answer.size(); i++) {
                cout << answer[i];
            }
            cout << endl;
        }
    }
    for (int i = from; i < C; i++) {
        answer[where] = alpha[i];
        recu(alpha, answer, where+1, i+1);
    }

}

int main(int argc, char const *argv[]) {
    cin >> L >> C;
    vector<char> alpha(C, 0), answer(L, 0);

    for (int i = 0; i < C; i++) {
        char c; cin >> c;
        alpha[i] = c;
    }
    sort(alpha.begin(), alpha.end());
    recu(alpha, answer, 0, 0);
    return 0;
}