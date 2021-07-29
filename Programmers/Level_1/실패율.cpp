#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pdi;

int stageCnt[501];

bool compare(pdi a, pdi b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pdi> fail;
    int sz = stages.size();

    for (int i = 0; i < sz; i++) {
        stageCnt[stages[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (sz == 0 || stageCnt[i] == 0) {
            fail.push_back({0, i});
        }
        else {
            double failure = (double)stageCnt[i] / sz;
            fail.push_back({failure, i});
        }
        sz -= stageCnt[i];
    }
    sort(fail.begin(), fail.end(), compare);

    for (int i = 0; i < fail.size(); i++) {
        answer.push_back(fail[i].second);
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    vector<int> ans = solution(5, stages);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}