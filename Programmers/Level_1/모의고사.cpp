#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int person[3] = {0}, maxPerson = 0;

    for (int i = 5; i < answers.size(); i++) {
        p1.push_back(p1[i-5]);
    }
    for (int i = 8; i < answers.size(); i++) {
        p2.push_back(p2[i-8]);
    }
    for (int i = 10; i < answers.size(); i++) {
        p3.push_back(p3[i-10]);
    }
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == p1[i]) {
            person[0]++;
        }
        if (answers[i] == p2[i]) {
            person[1]++;
        }
        if (answers[i] == p3[i]) {
            person[2]++;
        }
    }
    maxPerson = max(max(person[0], person[1]), person[2]);
    for (int i = 0; i < 3; i++) {
        if (maxPerson == person[i]) {
            answer.push_back(i+1);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}