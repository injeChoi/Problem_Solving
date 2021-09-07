#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(string name) {
    int answer = 0, idx = 0;
    string start = "";
    for (int i = 0; i < name.length(); i++) {
        start += "A";
    }
    while (name != start) {
        int MIN = 20;
        for (int i = 0; i < name.length(); i++) {
            if (name[i] == start[i]) {
                continue;
            }
            int dist = min(abs(idx - i), abs((int)(name.length()-1) - i + idx + 1));
            if (dist < MIN) {
                MIN = dist;
                idx = i;
            }
        }
        answer += MIN;
        if (name[idx] - start[idx] > 0) {
            if (name[idx] - start[idx] <= 13) {
                answer += name[idx] - start[idx];
            }
            else {
                answer += 25 - (name[idx] - start[idx]) + 1;
            }
        }
        start[idx] = name[idx];
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    solution("BBBAAAB");

    return 0;
}