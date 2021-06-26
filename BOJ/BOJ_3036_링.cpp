#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GCD(int a, int b) {
    return a % b ? GCD(b, a % b) : b;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N; i++) {
        int r; cin >> r;
        v.push_back(r);
    }

    for (int i = 1; i < v.size(); i++) {
        int gcd = GCD(v[0], v[i]);
        cout << v[0] / gcd << "/" << v[i] / gcd << endl;
    }

    return 0;
}