#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> score;
long long answer;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s; cin >> s;
        score.push_back(s);
    }
    sort(score.begin(), score.end());
    for (int i = 1; i <= N; i++) {
        answer += abs(i - score[i-1]);
    }
    cout << answer << '\n';
    return 0;
}