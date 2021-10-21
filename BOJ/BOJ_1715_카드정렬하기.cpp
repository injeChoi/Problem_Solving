#include <bits/stdc++.h>
using namespace std;

int N, sum;
priority_queue<int> pq;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        pq.push(-num);
    }
    if (pq.size() == 1) {
        cout << 0 << '\n';
        return 0;
    }
    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << -sum << '\n';
    return 0;
}