#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, N, M;
vector<int> A, B, combA, combB;
ll ans;

int main(int argc, char const *argv[]) {
    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        A.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        B.push_back(num);
    }

    // 벡터 별로 나올 수 있는 조합들의 합  
    for (int i = 0; i < A.size(); i++) {
        int sum = A[i];
        combA.push_back(sum);
        for (int j = i+1; j < A.size(); j++) {
            sum += A[j];
            combA.push_back(sum);
        }
    }
    for (int i = 0; i < B.size(); i++) {
        int sum = B[i];
        combB.push_back(sum);
        for (int j = i+1; j < B.size(); j++) {
            sum += B[j];
            combB.push_back(sum);
        }
    }
    // 탐색을 위해 정렬 
    sort(combB.begin(), combB.end());

    for (int i = 0; i < combA.size(); i++) {
        int gap = T - combA[i]; // A의 조합 수와 합이 T가 될 수 있는 숫자
        auto upper = upper_bound(combB.begin(), combB.end(), gap);
        auto lower = lower_bound(combB.begin(), combB.end(), gap);
        ans += (upper - lower); // gap이 몇개나 있는지 찾아서 더함, gap이 없으면 iterator.end() - iterator.end() = 0
    }
    cout << ans << endl;
    return 0;
}