#include <bits/stdc++.h>
using namespace std;

int R, C;
set<string> words;
vector<string> puzzle;


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string str; cin >> str;
        puzzle.push_back(str);
    }

    for (int i = 0; i < R; i++) {
        string str = "";
        for (int j = 0; j < C; j++) {
            if (puzzle[i][j] != '#')
                str += puzzle[i][j];
            else {
                if (str.length() > 1) 
                    words.insert(str);
                str = "";
            }
            if (str.length() > 1 && j == C-1) 
                words.insert(str);
        }
    }
    for (int i = 0; i < C; i++) {
        string str = "";
        for (int j = 0; j < R; j++) {
            if (puzzle[j][i] != '#')
                str += puzzle[j][i];
            else {
                if (str.length() > 1) 
                    words.insert(str);
                str = "";
            }
            if (str.length() > 1 && j == R-1) 
                words.insert(str);
        }
    }

    auto iter = words.begin();
    cout << *iter << endl;
    return 0;
}