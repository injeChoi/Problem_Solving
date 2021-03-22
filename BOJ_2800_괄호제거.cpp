#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<pair<int, int> > bracket;
string input;
bool visited[201];
bool ch[201];
set<string> ans;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int cnt, int idx) {
    if (cnt > 0) {
        string s = "";
        for (int i = 0; i < input.size(); i++) {
            if (ch[i]) 
                continue;
            s += input[i];
        }
        ans.insert(s);
    }
    for (int i = idx; i < bracket.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            ch[bracket[i].first] = true;
            ch[bracket[i].second] = true;
            DFS(cnt+1, idx+1);
            // 여러 괄호 쌍 중 한 쌍만 제거하고 DFS로 풀어나가면서 나오는 답 들과
            // 제거한 한 쌍 말고 다른 한 쌍을 제거하고 DFS를 돌리면 다른 답들이 나올 수 있다.
            visited[i] = false;
            ch[bracket[i].first] = false;
            ch[bracket[i].second] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(')
            s.push(i);
        else if (input[i] == ')') {
            bracket.push_back({s.top(), i});
            s.pop();
        }
    }
    DFS(0, 0);

    for (auto iter = ans.begin(); iter != ans.end(); iter++) 
        cout << *iter << endl;

    return 0;
}