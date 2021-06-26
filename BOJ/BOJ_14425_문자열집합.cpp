#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
set<string> S;
string str;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        S.insert(str);
    }
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (S.find(str) != S.end()) 
            cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}