#include <bits/stdc++.h>
using namespace std;

string N;
bool zero;
unsigned long long total;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    
    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '0')
            zero = true;
        total += N[i] - '0';
    }

    if (zero && !(total % 3)) {
        sort(N.begin(), N.end());
        reverse(N.begin(), N.end());
        cout << N << endl;
    }
    else 
        cout << -1 << endl;

    return 0;
}