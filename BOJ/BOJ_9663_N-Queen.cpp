#include <bits/stdc++.h>
using namespace std;

int N, total;
int dx[16], dy[16]; // x축, y축 말 위치 정보 저장 

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int func(int y, int x) {
    int ret = 0;
    // 가지치기 (back tracking)
    for (int i = 0; i < y; i++) {
        if (dx[i] == x) {   // 세로 겹침
            return 0;
        }
        if (dy[i] == y) {   // 가로 겹침
            return 0;
        }
        if (abs(dx[i]-x) == abs(dy[i] - y)) {   // 대각 겹침 
            return 0;
        }
    }
    // 종료조건
    if (y == N - 1) {   // 말의 위치가 체스판의 마지막 줄 까지 도달하고 배치가 성공적이면  
        return 1;
    }
    // 말의 위치 기억
    dx[y] = x;
    dy[y] = y;

    for (int i = 0; i < N; i++) { // DFS 
        ret += func(y+1, i);    // 특정 행에서 배치 찾기 시작 
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        total += func(0, i);    // 특정 열에서 배치 찾기 시작 
    }
    cout << total << endl;
    return 0;
}