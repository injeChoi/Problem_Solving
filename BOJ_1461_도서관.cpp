#include <bits/stdc++.h>
using namespace std;

int N, M;
int book;
int sum, idx, Min = 20000, near, target;
vector<int> v;
vector<int> abs_v;
bool even = false, odd = false;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(int n1, int n2) {
    int elements = n2 - n1 + 1;

    if (elements % 2 == 0) {
        for (int i = n2; i >= n1; i-=M) {
            if (book > 0) {
                sum += abs(v[i] * 2);
                book--;
            }
            else 
                sum += abs(v[i]);
        }
    }
    else {
        sum += v[n2];
        book--;
        for (int i = n1; i <= n2; i+=M) {
            if (book > 0) {
                sum += abs(v[i] * 2);
                book = book - M;
            }
            else 
                sum += abs(v[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> book;
        v.push_back(book);
        abs_v.push_back(abs(book));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        if (abs(v[i] - target) < Min) {
            Min = abs(v[i] - target);
            idx = i;
        }
    }

    if (v[idx] > 0) even = true;
    else odd = true;

    if (even) {
        solve(0, idx-1);
        solve(idx, N-1);
    }
    else {
        solve(0, idx);
        solve(idx+1, N-1);
    }

    cout << sum << endl;
    return 0;
}