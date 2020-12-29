#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    string str; cin >> str;
    int N; cin >> N;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        tmp.append(tmp);
        if (tmp.find(str) != string::npos)
            cnt++;
        else 
            continue;
    }
    cout << cnt << endl;;
    return 0;
}