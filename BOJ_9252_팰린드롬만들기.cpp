#include <bits/stdc++.h>
using namespace std;

string name;
int len, cnt, idx;
vector<pair<char, bool> > v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Palindrome () {
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (v[i].second == false && v[j].second == false && v[i].first == v[j].first) {
                v[i].second = true;
                v[j].second = true;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> name;
    len = name.length();
    char str[len];

    for (int i = 0; i < len; i++) 
        v.push_back({name[i], false});

    sort(v.begin(), v.end());
    Palindrome();

    for (int i = 0; i < len; i++) {
        if (v[i].second == false) {
            cnt++; 
            idx = i;
        }
    }

    char ch = v[idx].first;
    v.erase(v.begin()+idx);
    
    if (cnt > 1) {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }
    if (len % 2 == 0 && cnt == 0) {
        for (int i = 0; i < len/2; i++) {
            str[i] = v[i*2].first;
            str[len-1-i] = v[i*2].first;
        }
    }
    else if (len % 2 == 1 && cnt == 1) {
        str[len/2] = ch;
        for (int i = 0; i < len/2; i++) {
            str[i] = v[i*2].first;
            str[len-1-i] = v[i*2].first;
        }
    }

    for (int i = 0; i < len; i++) 
        cout << str[i];
    cout << endl;
    return 0;
}