// Range Update Point Query(누적합) 사용해서 시간 초과 극복 
// 장애물의 시작점에 +1, 마지막점 +1 구간에 -1을 넣음 
// 장애물 구간의 누적합을 계산 

#include <bits/stdc++.h>
using namespace std;

int N, H, ans = -1, cnt;
int sum[500010];

int main() {
    cin >> N >> H;
    for (int i = 0 ; i < N ; i++) {
        int bar; cin >> bar;
        if (i % 2 == 0) {
            sum[1]++;
            sum[bar + 1]--;
        }
        else {
            sum[H - bar + 1]++; // 종유석은 천장에서 자라기 시작하므로 끝을 의미하는 -1을 넣어줄 필요가 없음 
        }
    }
    for (int i = 1; i <= H; i++) {
        sum[i] += sum[i-1];
        if (ans == -1 || sum[i] < ans) {    // 누적합이 최소가 되는 부분이 생기면 파괴해야하는 장애물을 1로 초기화 
            ans = sum[i];
            cnt = 1;
        }
        else if (sum[i] == ans) {           // 아니면 파괴해야하는 장애물 개수 1씩 증가 
            cnt++;
        }
    }
    cout << ans << ' ' << cnt << endl;
}