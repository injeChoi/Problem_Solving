#include <bits/stdc++.h>
using namespace std;

string A, B, ans, tmp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> A >> B;

    if (A.length() > B.length()) {
        for (int i = 0; i < A.length() - B.length(); i++) 
            tmp += '0';
        B = tmp + B;
    }
    else if (A.length() < B.length()) {
        for (int i = 0; i < B.length() - A.length(); i++) 
            tmp += '0';
        A = tmp + A;
    }

    bool increase = 0;
    for (int i = A.length()-1; i >= 0; i--) {
        int sum = A[i] - '0' + B[i] - '0';

        if (increase) 
            sum++;

        if (sum >= 10) {
            increase = 1;
            ans += to_string(sum-10);
        }
        else {
            increase = 0;
            ans += to_string(sum);
        }
    }
    if (increase) 
        ans += "1";

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}