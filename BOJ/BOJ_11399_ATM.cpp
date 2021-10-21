#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> P;
int total;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int time; cin >> time;
        P.push_back(time);
    }
    sort(P.begin(), P.end());
    for (int i = 1; i < N; i++) {
        P[i] = P[i-1] + P[i];
    }
    for (int i = 0; i < N; i++) {
        total += P[i];
    }
    cout << total << '\n';
    return 0;
}