#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_map<int, int> mapLottos;
    int zero = 0, correct = 0, num = 0;

    for (int i : lottos) {  // 0 개수 찾기, map에 원소 개수 추가
        if (i == 0) {
            zero++;
        }
        ++mapLottos[i];
    }
    for (int i : win_nums) {    // 맞춘 번호 개수 찾기 
        auto ret = mapLottos.find(i);
        if (ret != mapLottos.end()) {
            correct++;
        }
    }
    num = zero + correct;
    num = (num == 0) ? 1 : (zero + correct);    // 0도 없고 맞춘 것도 없으면 
    answer.push_back(7-num);
    num = (correct != 0) ? (7-correct) : 6;     // 맞춘게 없으면 
    answer.push_back(num);
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> l = {0, 0, 0, 0, 0, 0};
    vector<int> w = {38, 19, 20, 40, 15, 25};
    vector<int> ret = solution(l, w);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}