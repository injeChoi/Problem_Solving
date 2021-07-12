#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int cache[6][6];

int recu(int n, int r) {
    if (r == 0) {
        return 1;
    }
    if (n < r) {
        return 0;
    }
    if (cache[n][r] != 0) {
        return cache[n][r];
    }
    int tmp = recu(n-1, r-1) + recu(n-1, r);
    cache[n][r] = tmp;
    return cache[n][r];
}

int main(int argc, char const *argv[]) {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << recu(M, N) << endl;;
    }
    return 0;
}