#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000

int N, M, K;
int cache[101][101];
char answer[201];

int DP(int a, int z) {
    if (a == 0 || z == 0) {
        return 1;
    }
    if (cache[a][z] != -1) {    // 이미 계산했던게 있으면 리턴 
        return cache[a][z];
    }
    cache[a][z] = DP(a-1, z) + DP(a, z-1);  // a하나 더 쓴거 + z하나 더 쓴거 경우의 수

    if (cache[a][z] >= MAX) {   // MAX개 이상의 경우의 수는 고려할 필요가 없다
        cache[a][z] = MAX;      // 어차피 MAX개 이하의 경우의 수만 입력으로 들어오니까 
    }                           // MAX개 이상의 경우의 수가 생기더라도 최종 범위는 MAX까지 일 뿐 
    return cache[a][z];
}

int main(int argc, char const *argv[]) {
    cin >> N >> M >> K;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            cache[i][j] = -1;
        }
    }
    // 문자 조합의 개수가 10억 미만이면 찾으려는 문자가 없을 수도 있는 것이므로 -1 출력 
    if (DP(N, M) < K) {
        cout << -1 << endl;
        return 0;
    }
    //앞으로 사용할 수 있는 문자의 개수 
    int cntA = N, cntZ = M;
    // 문자열 채우기 
    for (int i = 0; i < N + M; i++) {
        if (cntA > 0) { // 아직 a로 채울 수 있으면 
            int tmp = DP(cntA-1, cntZ); // a를 하나 더 붙이고 현재 단계에서 포함되는 문자열의 개수 
            if (tmp < K) {  // 경우의 수가 K 미만이면 다른 지역에 있을 것 
                answer[i] = 'z';
                K -= tmp;   // 다음 단계에서 경우의 수는 이 전 단계보다 줄어듦 (아닌 놈들은 제껴야되니까)
                cntZ--;
            }
            else {  // 아직 동일한 단계 안에서 찾는 중인 것 
                answer[i] = 'a';
                cntA--;
            }
        }
        else {          // a로 채울 수 없으면 나머지는 전부 z로 채우기 
            answer[i] = 'z';
        }
    }
    cout << answer+K-1 << endl;
    return 0;
}