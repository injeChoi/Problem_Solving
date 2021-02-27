#include <bits/stdc++.h>
using namespace std;

string A, B, s, tmp;
vector<int> diff;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> A >> B;
    tmp = A;
    
    int idx = 1;
    while (A.length() < B.length()+1) {
        int cnt = 0;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i])
                cnt++;
        }
        diff.push_back(cnt);
        A = tmp;
        s = B.substr(0, idx++);
        A = s + A;
    }
    sort(diff.begin(), diff.end());

    cout << diff[0] << endl;
    return 0;
}