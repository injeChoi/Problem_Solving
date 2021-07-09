#include <bits/stdc++.h>
using namespace std;

int N, K, cnt, ans;

void check() {
    if (cnt == K) {
        cout << ans << endl;
        exit(0);
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> K;
    bool *SOE = new bool[N+1];

    for (int i = 2; i <= N; i++)
        SOE[i] = true;

    for (int i = 2; i <= N; i++) {
        if(SOE[i] == 0)
            continue;
        else {
            SOE[i] = false;
            cnt++;
            ans = i;
            check();
            for (int j = i+i; j <= N; j += i) {
                if (SOE[j]) {
                    SOE[j] = false;
                    cnt++;
                    ans = j;
                    check();
                }
            }
        }
    }
    return 0;
}