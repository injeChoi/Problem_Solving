#include <bits/stdc++.h>
using namespace std;

int N, M;
int book, sum, idx, far;
vector<int> pv, nv;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp (int a, int b) { return a > b; }

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> book;
        if (book > 0) pv.push_back(book);
        else nv.push_back(-(book));
    }

    sort(pv.begin(), pv.end(), cmp);
    sort(nv.begin(), nv.end(), cmp);

    for (int i = 0; i < pv.size(); i += M) {
        if (pv[i] > far) {
            sum += pv[i];
            sum += far;
            far = pv[i];
        }
        else
            sum += pv[i] * 2;
    }

    for (int i = 0; i < nv.size(); i += M) {
        if (nv[i] > far) {
            sum += nv[i];
            sum += far;
            far = nv[i];
        }
        else
            sum += nv[i] * 2;
    }

    cout << sum << endl;
    return 0;
}