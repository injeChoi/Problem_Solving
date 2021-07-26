#include <bits/stdc++.h>
using namespace std;

bool loan[31], loaned[31];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    answer -= lost.size();

    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                loan[i] = true;
                loaned[j] = true;
                answer++;
            }
        }
    }
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            cout << loan[i] << ' ' << loaned[j] << endl;
            if (loan[i] || loaned[j]) {
                continue;
            }
            if (reserve[i] == lost[j]-1 || reserve[i] == lost[j]+1) {
                answer++;
                loan[i] = true;
                loaned[j] = true;
            }
        }
    }
    return answer;
}