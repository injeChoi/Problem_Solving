#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string s;
long long cnt;


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> s;
    int N = stoi(s);
    int tmp1 = 9, tmp2 = 1;
    int digit = s.length();

    for (int i = 1; i < digit; i++) {
        cnt += tmp1 * i;
        tmp1 *= 10;
        tmp2 *= 10;
    }

    cnt += (N - tmp2 + 1) * digit;
    cout << cnt << endl;
    
    return 0;
}
