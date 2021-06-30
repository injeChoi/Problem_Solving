#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
// auto ret = mapParticipant.insert({participant[i], cnt});
// if (!ret.second) {
//     cnt = mapParticipant.find(participant[i]);
// }
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mapParticipant;
    for (int i = 0; i < participant.size(); i++) {
        string name = participant[i];
        mapParticipant[name];
    } 
    for (auto iter : mapParticipant) {
        cout << iter.first << " " << iter.second << endl;
    }
    
    return answer;
}

int main(int argc, char const *argv[]) {
    init();
    //freopen("input.txt", "r", stdin);
    vector<string> participant;
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");
    vector<string> completion;
    participant.push_back("eden");
    participant.push_back("kiki");
    cout << solution(participant, completion) << endl;
    return 0;
}