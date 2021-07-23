#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(string s) {
    int answer = 0, loop = 0;

    while (loop < 10) {
        switch (loop) {
            case 0:
                while (s.find("zero") != string::npos) {
                    int idx = s.find("zero");
                    s.replace(idx, 4, "0");
                }
                break;
            case 1:
                while (s.find("one") != string::npos) {
                    int idx = s.find("one");
                    s.replace(idx, 3, "1");
                }
                break;
            case 2:
                while (s.find("two") != string::npos) {
                    int idx = s.find("two");
                    s.replace(idx, 3, "2");
                }
                break;
            case 3:
                while (s.find("three") != string::npos) {
                    int idx = s.find("three");
                    s.replace(idx, 5, "3");
                }
                break;
            case 4:
                while (s.find("four") != string::npos) {
                    int idx = s.find("four");
                    s.replace(idx, 4, "4");
                }
                break;
            case 5:
                while (s.find("five") != string::npos) {
                    int idx = s.find("five");
                    s.replace(idx, 4, "5");
                }
                break;
            case 6:
                while (s.find("six") != string::npos) {
                    int idx = s.find("six");
                    s.replace(idx, 3, "6");
                }
                break;
            case 7:
                while (s.find("seven") != string::npos) {
                    int idx = s.find("seven");
                    s.replace(idx, 5, "7");
                }
                break;
            case 8:
                while (s.find("eight") != string::npos) {
                    int idx = s.find("eight");
                    s.replace(idx, 5, "8");
                }
                break;
            case 9:
                while (s.find("nine") != string::npos) {
                    int idx = s.find("nine");
                    s.replace(idx, 4, "9");
                }
                break;
            
            default:
                break;
        }
        loop++;
    }
    answer = stoi(s);
    return answer;
}