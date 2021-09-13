#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string, string> mm;
    unordered_map<string, int> hash_map;
    set<pair<string, string>> s;

    for (string iter : report) {
        string user = "", rep = "";
        for (int i = 0; i < iter.length(); i++) {
            if (iter[i] == ' ') {
                user = iter.substr(0, i);
                rep = iter.substr(i+1, iter.length());
                break;
            }
        }
        auto check = s.insert({rep, user});
        if (check.second) {
            mm.insert({rep, user});
        }
    }
    for (string str : id_list) {
        int cnt = 0;
        auto range = mm.equal_range(str);
        for (auto i = range.first; i != range.second; i++) {
            cnt++;
        }
        if (k <= cnt) {
            for (auto i = range.first; i != range.second; i++) {
                ++hash_map[i->second];
            }
        }
    }
    for (string str : id_list) {
        if (hash_map.find(str) != hash_map.end()) {
            answer.push_back(hash_map[str]);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    solution(id_list, report, 2);

    return 0;
}