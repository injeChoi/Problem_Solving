#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    vector<int> a = {-1,0,1};
    vector<int> b = {1,0,-1};
    cout << solution(a, b) << endl;
    return 0;
}