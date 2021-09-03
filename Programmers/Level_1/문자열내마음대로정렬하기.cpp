#include <bits/stdc++.h>
using namespace std;
typedef pair<char, string> pcs;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pcs> v;
    for (int i = 0; i < strings.size(); i++) {
        v.push_back({strings[i][n], strings[i]});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    //freopen("input.txt", "r", stdin);
    vector<string> strings = {"sun", "bed", "car"};
    sort(strings.begin(), strings.end());
    int n = 1;
    solution(strings, n);
    return 0;
}