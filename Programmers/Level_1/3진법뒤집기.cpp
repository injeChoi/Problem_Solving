#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0, idx = 0;
    string tmp = "";

    while (n > 0) {
        int mod = n % 3;
        n = n / 3;
        tmp += to_string(mod);
    }
    cout << tmp << endl;
    reverse(tmp.begin(), tmp.end());
    cout << tmp << endl;

    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] != '0') {
            if (i == 0) {
                answer += tmp[i] - '0';
            }
            else {
                answer += (tmp[i] - '0') * pow(3, idx);
            }
        }
        idx++;
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    cout << solution(125) << endl;
    return 0;
}