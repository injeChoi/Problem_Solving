/*
* map에 insert하는 방법은 두 가지 
* map<string, int> m 으로 선언 
* 1. m.insert({"key", 123});
* 2. m["key"] = 123; 
* operator [] 는 find-or-add operator 역할을 수행한다 
*/

#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mapParticipant;
    for (int i = 0; i < participant.size(); i++) {
        string name = participant[i];
        ++mapParticipant[name];
    } 
    for (string iter : completion) {
        --mapParticipant[iter];
    }
    for (auto iter : mapParticipant) {
        if (iter.second > 0) {
            answer = iter.first;
            break;
        }
    }
    return answer;
}