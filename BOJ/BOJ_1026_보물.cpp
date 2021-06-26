#include <bits/stdc++.h>
using namespace std;

int N, input, ans;
vector<int> A, B;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int cmp(int a, int b) {
    return a > b;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> input;
        A.push_back(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> input;
        B.push_back(input);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    
    for (int i = 0; i < A.size(); i++) 
        ans += A[i] * B[i];
    
    cout << ans << endl;
    return 0;
}