#include <bits/stdc++.h>
using namespace std;

string doc, str;
int cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    getline(cin, doc);
    getline(cin, str);

    while (doc.length() >= str.length()) {
        if (doc.find(str) != string::npos) {
            cnt++;
            int idx = doc.find(str);
            doc = doc.substr(idx + str.length());
        }
        else break;
    }
    cout << cnt << endl;
    return 0;
}