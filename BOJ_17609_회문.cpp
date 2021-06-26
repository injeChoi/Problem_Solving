#include <bits/stdc++.h>
using namespace std;

int T;
string str, s1, s2;
bool isZero;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool Palindrome() {
    int size = str.length();
    s1 = str.substr(0, size/2);
    if (str.length() % 2 == 1)
        s2 = str.substr((size/2)+1, size-1);
    else 
        s2 = str.substr((size/2), size-1);

    reverse(s2.begin(), s2.end());
    if (s1 == s2) return true;

    return false;
}

bool can_palindrome(int left, int right, bool skip) {
    if (left > right)
        return true;
    if (str[left] == str[right])
        return can_palindrome(left+1, right-1, skip);
    else if (skip) 
        return max(can_palindrome(left+1, right, false), can_palindrome(left, right-1, false));
    else 
        return false;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;

    while (T--) {
        cin >> str;

        if (Palindrome()) 
            cout << 0 << endl;
        else if (can_palindrome(0, str.length()-1, 1)) 
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}