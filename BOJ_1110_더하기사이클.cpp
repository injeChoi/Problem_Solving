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

    int N; cin >> N;
    int first, second, attach, newNumber = 0, cnt = 0;
    int tmp = N;

    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    while(N != newNumber) {
        first = tmp / 10;
        second = tmp % 10;
        attach = (first + second) % 10;
        newNumber = second * 10 + attach;
        tmp = newNumber;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
