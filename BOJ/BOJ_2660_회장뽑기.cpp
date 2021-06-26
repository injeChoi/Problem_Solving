#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, MIN;
int Map[51][51];
vector<int> candidate;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    MIN = N; // 회장 후보 인원 수 

    // 초기화 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) 
            Map[i][j] = INF;
        Map[i][i] = 0;
    }

    // 친구 거리 1 인 사이 
    while (1) {
        int num1, num2;
        cin >> num1 >> num2;

        if (num1 == -1 && num2 == -1) {
            break;
        }
        Map[num1][num2] = 1;
        Map[num2][num1] = 1;
    }

    // Floyd 알고리즘 
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) 
            for (int j = 1; j <= N; j++)
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
    }

    for (int i = 1; i <= N; i++) {
        int score = 0;

        for (int j = 1; j <= N; j++) {   // 점수가 가장 높은(안 좋은) 사람 찾기 
            score = max(score, Map[i][j]);
        }
        if (MIN > score) {              // 더 좋은 점수를 가진 후보 발견하면 초기화 
            MIN = score;
            candidate.clear();
        }
        if (MIN == score) {             // 현재까지 가장 좋은 점수 가진 후보들을 후보군에 추가 
            candidate.push_back(i);
        }
    }

    cout << MIN << " " << candidate.size() << endl;
    for (int i = 0; i < candidate.size(); i++) {
        cout << candidate[i] << " ";
    }
    cout << endl;

    return 0;
}