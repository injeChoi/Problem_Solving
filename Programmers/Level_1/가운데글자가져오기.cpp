#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    if (s.length() == 1) {
        answer += s;
    }
    else if (s.length() % 2 == 0) {
        answer += s.substr(s.length()/2-1, 2);
    }
    else {
        answer += s.substr(s.length() / 2 , 1);
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    solution("qwertyuiop");
    return 0;
}