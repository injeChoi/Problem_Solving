#include <bits/stdc++.h>
using namespace std;
long long hashing, R = 1;
int MOD = 1234567891, L;
string str;

int main(int argc, char const *argv[]) {
    cin >> L;
    cin >> str;
    // (a * b) mod n = {(a mod n) * (b mod n)} mod n
    for (int i = 0; i < str.length(); i++) {
        hashing = (hashing + (str[i] - 'a' + 1) * R) % MOD;
        R = (R * 31) % MOD;
    }
    cout << hashing << endl;
    return 0;
}