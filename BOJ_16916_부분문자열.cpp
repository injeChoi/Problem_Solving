#include <bits/stdc++.h>
using namespace std;

char S[1000001], P[1000001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> S >> P;

    char *ptr = strstr(S, P);

    ptr != NULL ? cout << 1 << endl : cout << 0 << endl;
    return 0;
}