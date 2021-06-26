#include <bits/stdc++.h>
using namespace std;

int A, B, cnt;
string strB;

int main(int argc, char const *argv[]) {
    cin >> A >> B;
    while (1) {
        strB = to_string(B);
        if (A == B) {
            cout << cnt + 1 << endl;
            return 0;
        }
        if (strB.back() > 50 && (B % 2 == 1)) {
            cout << -1 << endl;
            return 0;
        }
        if (A > B) {
            cout << -1 << endl;
            return 0;
        }
        if (strB.back() == '1') {
            strB.pop_back();
            B = stoi(strB);
            cnt++;
        }
        else {
            B /= 2;
            cnt++;
        }
    }
    return 0;
}