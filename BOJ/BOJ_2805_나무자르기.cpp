#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll tree[1000000];
ll answer;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cutable(ll h) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] >= h) {
            sum += tree[i] - h;
        }
        if (sum >= M) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    ll lower = 0, upper = 1000000000, mid;
    while (lower <= upper) {
        mid = (lower + upper) / 2;
        if (cutable(mid)) {
            if (answer < mid) {
                answer = mid;
            }
            lower = mid + 1;
        } 
        else {
            upper = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}
