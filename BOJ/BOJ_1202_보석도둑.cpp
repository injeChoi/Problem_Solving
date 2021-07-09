#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, K, p_j;
long long ans;
vector<pii> jewerly;
vector<int> bag;
priority_queue<int, vector<int>, less<int>> pq;

int main(int argc, char const *argv[]) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int M, V; cin >> M >> V;
        jewerly.push_back({M, V});
    }
    for (int i = 0; i < K; i++) {
        int C; cin >> C;
        bag.push_back(C);
    }
    sort(jewerly.begin(), jewerly.end());
    sort(bag.begin(), bag.end());

    for (int i = 0; i < K; i++) {
        int curBag = bag[i];
        // 정렬된 순서의 현재 보석 무게가 현재 가방에 들어갈 수 있으면 
        while (p_j < N && jewerly[p_j].first <= curBag) {
            pq.push(jewerly[p_j].second);   // 우선순위 큐에 보석의 가치를 큰 순으로 정렬해서 넣음 
            p_j++;                          // 가방에 들어갈 수 있는 다음 보석 확인 
        }
        if (!pq.empty()) {                  // 가방에 들어갈 수 있는 보석 중 가장 가치가 높은 보석의 가치를 답에 추가 
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}