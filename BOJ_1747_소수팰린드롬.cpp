#include <bits/stdc++.h>
using namespace std;
#define MAX 1004000

int N;
string s1, s2, str;
vector<bool> isPrime(MAX, 1);

void SOE() {
    isPrime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i+i; j < MAX; j+=i) 
            isPrime[j] = false;
    }
}

bool Palindrome(int num) {
    str = to_string(num);
    int size = str.length();
    s1 = str.substr(0, size/2);
    if (str.length() % 2 == 1)
        s2 = str.substr((size/2)+1, size-1);
    else 
        s2 = str.substr((size/2), size-1);

    reverse(s2.begin(), s2.end());

    if (s1 == s2) 
        if (isPrime[num]) 
            return true;

    return false;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    SOE();
    
    while (N <= MAX) {
        if (Palindrome(N)) {
            cout << N << endl;
            break;
        }
        N++;
    }
    
    return 0;
}