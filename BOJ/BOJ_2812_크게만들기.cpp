#include <bits/stdc++.h>
using namespace std;

int N, K;
string num, answer;
stack<int> s;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> K >> num;
    int k = K;

    for (int i = 0; i < num.length(); i++) {
        int n = num[i] - '0';

        if (s.empty() || K == 0) {
            s.push(n);
            continue;
        }
        if (s.top() >= n) {
            s.push(n);
        }
        else {
            while (K && !s.empty() && s.top() < n) {
                K--;
                s.pop();
            }
            s.push(n);
        }
    }
    while (!s.empty()) {
        answer += to_string(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    for (int i = 0; i < N-k; i++) {
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}