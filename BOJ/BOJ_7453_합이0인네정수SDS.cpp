#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A, B, C, D, combAB, combCD;
int N, cnt;
ll ans;

int main(int argc, char const *argv[]) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            combAB.push_back(A[i] + B[j]);
            combCD.push_back(C[i] + D[j]);
        }
    }

    sort(combAB.begin(), combAB.end());
    sort(combCD.begin(), combCD.end());

    int r = combCD.size() - 1;
    for (int ab = 0; ab < combAB.size(); ab++) {
        int target = -(combAB[ab]);
        if (ab > 0 && combAB[ab] == combAB[ab - 1]) {
            ans += cnt;
        }
        else {
            cnt = 0;
            while (0 <= r && target < combCD[r]) {
                r--;
            }
            while (0 <= r && target == combCD[r]) {
                cnt++;
                r--;
            }
            ans += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}