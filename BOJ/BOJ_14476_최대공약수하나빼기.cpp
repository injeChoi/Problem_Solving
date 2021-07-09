#include <bits/stdc++.h>
using namespace std;

int N, ans = -1, loser;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main(int argc, char const *argv[]) {
    cin >> N;
    vector<int> v(N+2, 0);
    vector<int> leftGCD(N+2, 0);
    vector<int> rightGCD(N+2, 0);

    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        v[i] = num;
    }
    // 왼쪽에서 부터 숫자 하나씩 늘려가며 GCD 구한 값 저장 
    for (int i = 1; i <= N; i++) {
        leftGCD[i] = GCD(leftGCD[i-1], v[i]);
    }
    // 오른쪽에서 부터 숫자 하나씩 늘려가며 GCD 구한 값 저장 
    for (int i = N; i > 0; i--) {
        rightGCD[i] = GCD(rightGCD[i+1], v[i]);
    }
    // 해당 위치의 직전 최대공약수와 이후 최대공약수의 최대공약수가 전체의 최대공약수가 된다
    for (int i = 1; i <= N; i++) {
        int curGCD = GCD(leftGCD[i-1], rightGCD[i+1]);  // 특정 숫자를 뺀 전체의 최대공약수 
        if (v[i] % curGCD == 0) {   // 빼려는 숫자가 K의 약수가 되면 안 됨 
            continue;
        }
        if (ans < curGCD) { // 전체의 가장 큰 최대 공약수 
            ans = curGCD;
            loser = v[i];   // 빼려는 숫자 저장 
        }
    }
    if (ans == -1) {
        cout << ans << endl;
    }
    else {
        cout << ans << " " << loser << endl;
    }
    return 0;
}