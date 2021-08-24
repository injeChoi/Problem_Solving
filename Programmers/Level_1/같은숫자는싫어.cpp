#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] != arr[i+1]) {
            answer.push_back(arr[i+1]);
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);

    return 0;
}