#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); i++) {
        if (65 <= new_id[i] && new_id[i] <= 90) {
            answer += new_id[i] + 32;
        }
        else if (97 <= new_id[i] && new_id[i] <= 122) {
            answer += new_id[i];
        }
        else if (48 <= new_id[i] && new_id[i] <= 57) {
            answer += new_id[i];
        }
        else if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {    //strchr(".-_", ch)로 치환 가능 
            answer += new_id[i];
        }
    }
    for (int i = 0; i < answer.length()-1; ) {
        if (answer[i] == '.' && answer[i+1] == '.') {
            string tmp1 = answer.substr(0, i+1);
            string tmp2 = answer.substr(i+2, answer.length());
            answer = tmp1 + tmp2;
        }
        else {
            i++;
        }
    }
    if (answer[0] == '.') {
        answer.erase(0, 1);
    }
    if (answer.back() == '.') {
        answer.erase(answer.length()-1);
    }
    if (answer.empty()) {
        answer += "aaa";
    }
    if (answer.length() > 15) {
        answer = answer.substr(0, 15);
    }
    if (answer.back() == '.') {
        answer.erase(answer.length()-1);
    }
    while (answer.length() < 3) {
        answer += answer[answer.length()-1];
    }
    return answer;
}