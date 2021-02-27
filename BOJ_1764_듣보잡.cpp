#include <bits/stdc++.h>
using namespace std;

vector<string> v1, v2, name;
int N, M, cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        v1.push_back(str);
    }
    for (int i = 0; i < M; i++) {
        string str; cin >> str;
        v2.push_back(str);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < N; i++) {
        if (binary_search(v2.begin(), v2.end(), v1[i])) {
            cnt++;
            name.push_back(v1[i]);
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < name.size(); i++) 
        cout << name[i] << endl;
    
    return 0;
}