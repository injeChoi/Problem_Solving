#include <bits/stdc++.h>
using namespace std;

string S, T, tmp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> S >> T;

    while (S.length() != T.length()) {
        int len = T.length() - 1;
        if (T[len] == 'A') 
            T.pop_back();
        
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    S == T ? cout << 1 << endl : cout << 0 << endl;
    return 0;
}