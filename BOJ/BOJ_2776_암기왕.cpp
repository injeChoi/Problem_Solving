#include <bits/stdc++.h>
using namespace std;

int T, N, M, num;
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> num;
            if (binary_search(v.begin(), v.end(), num))
                cout << "1\n";
            else
                cout << "0\n";

        }
        v.clear();
    }

    return 0;
}