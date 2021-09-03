#include <bits/stdc++.h>
using namespace std;

int A, B;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    cin >> A >> B;
    solution(A, B);
    return 0;
}