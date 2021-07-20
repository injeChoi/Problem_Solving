/*
* s1을 가로, s2를 세로로 2차원 배열로 구성했을 때
* (i, j)에서 동일한 문자를 발견했을 때 
* (i-1, j-1) + 1 값을 넣어주면 된다. 
* 그러면 ABCD, ABC 라는 두 문자열이 있을 때, i=j=2일 때는 AB까지 공통부분 문자열로 인식하여 길이가 2가 되고
* i=j=3일 때 ABC까지 공통부분 문자열로 인식한다 
*/

#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[4001][4001];
int ans;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}