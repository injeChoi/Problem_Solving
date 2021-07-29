#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int chk(int num) {
    int cnt = 0;
    if (sqrt(num) - (int)sqrt(num) == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (chk(i)) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    cout << solution(24, 27) << endl;

    return 0;
}