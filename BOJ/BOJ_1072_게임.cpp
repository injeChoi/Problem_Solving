#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y, Z, bottom = 1, top = 1000000000, mid, ans = 1000000000;

int main(int argc, char const *argv[]) {
    cin >> X >> Y;
    Z = Y*100 / X;
    
    if (Z == 100 || Z == 99) {
        cout << -1 << endl;
        return 0;
    }
    // 이분 탐색 
    while (bottom <= top) {
        mid = (bottom + top) / 2;
        ll nextZ = (Y + mid) * 100 / (X + mid);
        if (Z < nextZ) {
            if (mid < ans) {
                ans = mid;
            }
            top = mid - 1;
        }
        else {
            bottom = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}