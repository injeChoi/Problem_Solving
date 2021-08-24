#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (int i : d) {
        if (budget - i >= 0) {
            budget -= i;
            answer++;
        }
        else {
            break;
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> d = {2,2,3,3};
    cout << solution(d, 10) << endl;
    return 0;
}