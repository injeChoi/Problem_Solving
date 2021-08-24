#include <bits/stdc++.h>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day = 0;

    if (a == 1) {
        day = 0;
    }
    else if (a == 2) {
        day += 31;
    }
    else {
        day += 60;
        for (int i = 3; i < a; i++) {
            if (i <= 7) {
                if (i % 2 == 1) day += 31;
                else  day += 30;
            }
            else {
                if (i % 2 == 1) day += 30;
                else day += 31;
            }
        }
    }
    day += b;
    int mod = day % 7 - 1;

    switch (mod) {
        case 0:
            answer = "FRI";
            break;
        case 1:
            answer = "SAT";
            break;
        case 2:
            answer = "SUN";
            break;
        case 3:
            answer = "MON";
            break;
        case 4:
            answer = "TUE";
            break;
        case 5:
            answer = "WED";
            break;
        case -1:
            answer = "THU";
            break;
        default:
            break;
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    cout << solution(3,3) << endl;
    return 0;
}