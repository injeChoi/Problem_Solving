#include <bits/stdc++.h>
using namespace std;

int N, mini = 123456789;
bool team[20];
int score[20][20];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void func(int idx, int cnt) {
    vector<int> start;
    vector<int> link;
    int start_score = 0, link_score = 0;

    if (cnt == N/2) {   // 팀 구성원이 총 인원의 반이 되면 실행 
        for (int i = 0; i < N; i++) {
            if (team[i]) {  // 반 나눈 인원으로 팀 구성 시작 
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }
        for (int i = 0; i < N/2; i++) {
            for (int j = 0; j < N/2; j++) {
                start_score += score[start[i]][start[j]]; // start 벡터에는 총 인원의 인덱스가 들어있다
                link_score += score[link[i]][link[j]];
            }
        }
        if (abs(start_score - link_score) < mini) { // 새로 구한 팀 밸런스 차이가 기존보다 작으면 바꾸기 
            mini = abs(start_score - link_score);
        }
        return; // 해당 팀 조합으로 계산한 함수 탈출 
    }
    for (int i = idx; i < N; i++) { // 중복된 조합이 발생하지 않게 해주는 부분 
        if (!team[i]) {         // 특정 팀에 참가한 인원이 아니라면 
            team[i] = true;     // 특정 팀에 참가할 인원으로 체크
            func(idx, cnt+1);   // 특정 구성원으로 만들어진 팀으로 점수 계산 
            team[i] = false;    // 다른 사람을 특정 팀에 넣기 위해 빼기 
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> score[i][j];
        }
    }

    func(0, 0); // DFS 시작 
    cout << mini << endl;
    return 0;
}