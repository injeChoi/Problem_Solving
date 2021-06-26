#include <bits/stdc++.h>
using namespace std;

string str, s1, s2;
int idx, N, M, num;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GCD (int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ':') {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < idx; i++) 
        s1 += str[i];
    
    for (int i = idx+1; i < str.length(); i++) 
        s2 += str[i];
    
    N = stoi(s1);
    M = stoi(s2);
    num = GCD(N, M);

    cout << N / num << ":" << M / num << endl;
    return 0;
}