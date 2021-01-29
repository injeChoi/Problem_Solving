#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;
string str;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int toInteger(string s) {
    int size = 0;
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch >= '0' && ch <= '9') {
            size += ch - 48;
        }
    }
    return size;
}

bool cmp(string a, string b){
    if (a.length() < b.length()) {
        return true;
    }
    else if (a.length() == b.length()) {
        int aSize = toInteger(a);
        int bSize = toInteger(b);

        if (aSize < bSize) {
            return true;
        }
        else if (aSize == bSize) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == b[i]) continue;
                else if (a[i] < b[i]) return true;
                else return false;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) 
        cout << v[i] << endl;
    
    return 0;
}
