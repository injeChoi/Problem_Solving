#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
vector<string> table;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int start, int end) {
    set<string> dupCheck;
    for (int j = 0; j < C; j++) {
        string tmp;
        for (int i = start; i <= end; i++) 
            tmp += table[i][j];
        if (dupCheck.find(tmp) == dupCheck.end())
            dupCheck.insert(tmp);
        else
            return false;
    }
 
    return true;
}
 
void binarySearch(int left, int right, int end) {
    if (left > right) 
        return;

    int mid = (left + right) / 2;
    bool flag = check(mid, end);
    if (flag) {
        if (ans < mid) 
            ans = mid;
        binarySearch(mid + 1, right, end);
    }
    else {
        binarySearch(left, mid - 1, end);
    }
}
 
int main() {
    init();
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str; cin >> str;
        table.push_back(str);
    }
    binarySearch(1, R - 1, R - 1);
    cout << ans << endl;
 
    return 0;
}