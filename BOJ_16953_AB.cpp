#include <bits/stdc++.h>
using namespace std;

int A, B, biggest = 1000000000;
queue<pair<int, int> > q;
bool isEnd;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> A >> B;

    q.push({A, 1});

    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num == B) {
            cout << cnt << endl;
            isEnd = true;
            break;
        }
        if (num * 2 <= B) {
            q.push({num * 2, cnt+1});
        }
        if (num  <= biggest / 10 && num * 10 + 1 <= B) {
            q.push({num * 10 + 1, cnt+1});
        }
    }
    if (!isEnd)
        cout << -1 << endl;
    return 0;
}