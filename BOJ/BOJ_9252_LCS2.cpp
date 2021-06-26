#include <bits/stdc++.h>
using namespace std;

string s1, s2, str;
int dp[1001][1001];
int ans;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> s1 >> s2;

    for (int i = 1; i <= s2.length(); i++) {
        for (int j = 1; j <= s1.length(); j++) {
            if (s1[j-1] == s2[i-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    ans = dp[s2.length()][s1.length()];
    int s1_len = s1.length();

    if (ans != 0) {
        cout << ans << endl;
        for (int i = s2.length(); i > 0; i--) {
            if (dp[i][s1_len] == 0)
                break;
            for (int j = s1_len; j > 0; j--) {
                if (dp[i][j] != dp[i][j-1]) {
                    str += s1[j-1];
                    s1_len = j - 1;
                    break;
                }
                if (dp[i][j] == dp[i-1][j]) 
                    break;
            }
        }
        reverse(str.begin(), str.end());   
        cout << str << endl;
    }
    else
        cout << ans << endl;
    
    return 0;
}