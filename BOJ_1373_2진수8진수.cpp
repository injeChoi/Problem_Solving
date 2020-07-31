#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string s;
vector<bool> v;
vector<int> ans;
int i, tmp;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0')
            v.push_back(false);
        else
            v.push_back(true);
    }

    while(!v.empty()) {
        if (i == 3) {
            ans.push_back(tmp);
            i = 0;
            tmp = 0;
        }
        else if (i == 0) {
            if (v.back())
                tmp += 1;
            else
                tmp += 0;
            i++;
            v.pop_back();
        }
        else if (i == 1) {
            if (v.back())
                tmp += 2;
            else
                tmp += 0;
            i++;
            v.pop_back();
        }
        else if (i == 2) {
            if (v.back())
                tmp += 4;
            else
                tmp += 0;
            i++;
            v.pop_back();
        }
    }
    ans.push_back(tmp);

    while(!ans.empty()) {
        cout << ans.back();
        ans.pop_back();
    }
    cout << endl;

    return 0;
}
