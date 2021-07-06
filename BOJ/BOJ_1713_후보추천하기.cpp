#include <bits/stdc++.h>
using namespace std;

int N, recommend, day;
unordered_map<int, int> candidate;   // 1. 후보 번호, 2. 추천 수
unordered_map<int, int> regi;        // 1. 후보 번호, 2. 등록 일 

int main(int argc, char const *argv[]) {
    cin >> N >> recommend;

    for (int i = 0; i < recommend; i++) {
        int idx; cin >> idx;
        int c = candidate.count(idx);                   // 이미 있는 후보인가 

        if (!c) {                                       // 없는 후보일 때
            if (candidate.size() < N) {                 // 게시판 허용치 이내면 
                ++candidate[idx];                       // 새로 등록 및 추천 수 1 증가 
                regi[idx] = day++;                      // 등록일 추가 
            }
            else {                                      // 허용치 밖이면 
                int recMin = 987654321, regiMin = 987654321, cnt = 0;
                vector<int> vm;
                
                for (auto iter : candidate) {           // 최소 추천 수 찾기 
                    recMin = min(recMin, iter.second);
                }
                for (auto iter : candidate) {           // 최소 추천 수의 개수 검사 
                    if (iter.second == recMin) {
                        cnt++;
                        vm.push_back(iter.first);
                    }
                }
                if (cnt > 1) {                          // 최소 추천 수가 1 초과일 때
                    for (auto iter : regi) {
                        for (int i = 0; i < vm.size(); i++) {   // 최소 추천 수인 애들만 검사 
                            if (iter.first == vm[i]) {
                                regiMin = min(regiMin, iter.second); 
                            }
                        }
                    }
                    for (auto iter : regi) {
                        if (regiMin == iter.second) {
                            candidate.erase(iter.first);
                            regi.erase(iter.first);
                            break;
                        }
                    }
                    ++candidate[idx];                       // 새로 등록 및 추천 수 1 증가 
                    regi[idx] = day++;
                }
                else {                                      // 최소 추천 수가 1개일 때 
                    for (auto iter : candidate) {
                        if (iter.second == recMin) {
                            candidate.erase(iter.first);
                            regi.erase(iter.first);
                            break;
                        }
                    }
                    ++candidate[idx];                       // 새로 등록 및 추천 수 1 증가 
                    regi[idx] = day++;
                }
            }
        }
        else {                                              // 이미 있는 후보라면 
            ++candidate[idx];                               // 추천 수 증가 
        }
    }

    map<int, int> ordered(candidate.begin(), candidate.end());
    for (auto iter : ordered) {
        cout << iter.first << ' ';
    }
    cout << endl;
    return 0;
}