#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0, tmp = 0;
    string num = "";
    vector<int> results;

    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] >= 48 && dartResult[i] <= 57) {
            num += dartResult[i];
            if (dartResult[i+1] >= 48 && dartResult[i+1] <= 57) {
                num += dartResult[i+1];
                i++;
            }
            tmp = stoi(num);
        }
        if (dartResult[i] == '*') {
            results[results.size()-1] *= 2;
            results[results.size()-2] *= 2;
        }
        if (dartResult[i] == '#') {
            results[results.size()-1] *= -1;
        }
        else {
            if (dartResult[i] == 'S') {
                results.push_back(tmp);
            }
            if (dartResult[i] == 'D') {
                tmp = pow(tmp, 2);
                results.push_back(tmp);
            }
            if (dartResult[i] == 'T') {
                tmp = pow(tmp, 3);
                results.push_back(tmp);
            }
            num = "";
        }
    }
    for (int i = 0; i < results.size(); i++) {
        answer += results[i];
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    solution("1D2S3T*");
    return 0;
}