#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int x1, y1, r1, x2, y2, r2, ans = 0;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = pow(x2 - x1, 2) + pow(y2-y1, 2); // 두 점 사이 거리 공식, 실수형의 오차를 없애기 위해 제곱근 없애서 계산 
        int tmp1 = pow(r1 + r2, 2);              // 두 원의 반지름 합의 제곱
        int tmp2 = pow(r2 - r1, 2);              // 두 원의 반지름 차의 제곱 

        if (d == 0) {
            if (tmp2 == 0)
                ans = -1;
            else 
                ans = 0;
        }

        else if (tmp1 == d || tmp2 == d)
            ans = 1;
        
        else if (tmp2 < d && d < tmp1)
            ans = 2;

        else 
            ans = 0;

        cout << ans << endl;
    }

    return 0;
}
