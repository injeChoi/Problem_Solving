#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    string board; cin >> board;
    string answer = "";
    int cnt = 0;
    for (int i = 0; i < board.length(); i++) {
        if (board[i] == 'X') {
            cnt++;
        }
        if (board[i] == '.' && cnt % 2 == 1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    if (cnt % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    cnt = 0;
    for (int i = 0; i < board.length(); i++) {
        if (board[i] == 'X') {
            cnt++;
            if (cnt == 4) {
                answer += "AAAA";
                cnt = 0;
            }
        }
        else {
            if (cnt == 2) {
                answer += "BB.";
            }
            else {
                answer += ".";
            }
            cnt = 0;
        }
        if (i == board.length()-1) {
            if (cnt == 4) {
                answer += "AAAA";
            }
            else if (cnt == 2) {
                answer += "BB";
            }
        }
    }
    cout << answer << '\n';
    return 0;
}