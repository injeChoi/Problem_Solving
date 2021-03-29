#include <bits/stdc++.h>
using namespace std;

string input, s1, s2;
int ans;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool Palindrome(string str) {
    int size = str.length();
    s1 = str.substr(0, size/2);

    if (str.length() % 2 == 1)
        s2 = str.substr((size/2)+1, size - (size/2)+1);
    else 
        s2 = str.substr((size/2), size - (size/2)+1);

    reverse(s2.begin(), s2.end());

    if (s1 == s2) 
        return true;

    return false;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> input;
    int size = input.length();

    if (Palindrome(input)) {
        ans = size - 1;
        if (Palindrome(input.substr(0, ans))) 
            ans = -1;
    }
    else 
        ans = size;

    cout << ans << endl;
    return 0;
}