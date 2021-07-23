#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto iter : commands) {
        int i = iter[0] - 1;
        int j = iter[1];
        int k = iter[2] - 1;
        vector<int> tmp(array.begin() + i, array.begin() + j);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
    }
    return answer;
}