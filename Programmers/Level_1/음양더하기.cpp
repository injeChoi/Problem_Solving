#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i]) {
           answer += absolutes[i]; 
        }
        else {
            answer -= absolutes[i];
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    vector<int> abs = {4, 7, 12};
    vector<bool> sign = {true, false, true};
    cout << solution(abs, sign) << endl;
    return 0;
}