#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> title;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 666; i < 3000000; i++) {
        int cnt = 0;
        string str = to_string(i);
        if (str.find("666") != string::npos) {
            title.push_back(i);
            if (title.size() == N) {
                i = 1000000;
                break;
            }
        }
    }

    cout << title[N-1] << endl;
    return 0;
}