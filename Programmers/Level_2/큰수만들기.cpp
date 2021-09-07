#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string solution(string number, int k) {
    string answer = "";
    int sz = number.size() - k;
    int start = 0;
    for (int i = 0; i < sz; i++) {
        char MAX = number[start];
        int idx = start;
        for (int j = start; j <= i+k; j++) {
            if (MAX < number[j]) {
                MAX = number[j];
                idx = j;
            }
        }
        start = idx + 1;
        answer += MAX;
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    solution("4177252841", 4);
    return 0;
}