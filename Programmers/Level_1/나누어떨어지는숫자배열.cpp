#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    if (answer.empty()) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(int argc, char const *argv[]) {
    init();

    return 0;
}