#include <iostream>
#include <algorithm>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    int n, d, cnt = 0, tmp = 0;
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        if (i < 10 && i == d)
            cnt++;
        else {
            tmp = i;
            while (tmp > 0) {
                if (tmp % 10 == d)
                    cnt++;
                tmp /= 10;
            }
        }
    }
    cout << cnt;
    return 0;
}
