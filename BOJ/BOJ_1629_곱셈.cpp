#include <bits/stdc++.h>
using namespace std;

int A, B, C;
long long num = 1, mul;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    // (A * B) % C = (A % C) * (B % C) mod C 임을 활용
    init();
    cin >> A >> B >> C;
    mul = A % C;

    while (B > 0) {
        if (B % 2 == 1) { // B가 홀수면 밑 수를 한 번 더 곱해준다 
            num *= mul;
            num %= C;
        }
        mul = (mul % C) * (mul % C) % C;
        B /= 2;
    }
    cout << num << endl;
    return 0;
}