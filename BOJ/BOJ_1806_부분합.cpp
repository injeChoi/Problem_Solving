#include <bits/stdc++.h>
using namespace std;

int N, S, Start, End, sum, ans = 987654321;
long long total;
vector<int> v;

int main(int argc, char const *argv[]) {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
        total += num;
    }
    if (S > total) {
        cout << 0 << endl;
        return 0;
    }
    while (Start <= End) {
        if (sum >= S) {
            ans = min(ans, End - Start);
            sum -= v[Start++];
        }
        else if (End == N) {
            break;
        }
        else {
            sum += v[End++];
        }
    }
    cout << ans << endl;
    return 0;
}