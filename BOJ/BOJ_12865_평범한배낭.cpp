#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[101][100001];
int w[101];
int v[101];
 
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            d[i][j] = d[i - 1][j];  // 우선 전 단계 최적 값을 임시로 저장해둔다 
            if (j - w[i] >= 0) {
                // i번째 물품을 배낭에 채우기 위해 
                // i번째 물품의 무게만큼의 공간을 배낭으로 부터 확보한다 (j - w[i])
                // 위 단계가 없으면 배낭은 이미 최고 무게로 담겨져 있기 때문에 i번째 물품을 넣을 공간이 없다
                // 확보한 공간에 전 단계에서의 최적 값과 지금 넣을 물품의 가치를 더한 값 중 더 최적인 것을 고른다  
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << d[n][k] << endl;
    return 0;
}
