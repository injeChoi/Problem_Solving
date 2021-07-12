#include <bits/stdc++.h>
using namespace std;

int N, idx, ans = 1, biggest = -1;
vector<int> number, prime;

void SOE(bool *isPrime) {
    for (int i = 2; i < biggest; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < sqrt(biggest); i++) {
        if (!isPrime[i]) {
            continue;
        }
        else {
            for (int j = i+i; j <= biggest; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        biggest = max(biggest, n);
        number.push_back(n);
    }
    bool *isPrime = new bool[biggest+1];
    SOE(isPrime);

    for (int i = 2; i < biggest; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
    int **cnt = new int*[N]; 
    for(int i = 0; i < N; ++i) { 
        cnt[i] = new int[prime.size()]; 
        memset(cnt[i], 0, sizeof(int)*prime.size()); // 메모리 공간을 0으로 초기화 
    }
    
    int *totalCount = new int[prime.size()];
    int *gcdCount = new int[prime.size()];

    // 소인수분해 + 소수 개수 카운팅 
    for (int i = 0; i < N; i++) {
        int num = number[i];
        for (int j = 0; j < prime.size(); j++) {
            while (num % prime[j] == 0) {
                cnt[i][j]++;
                totalCount[j]++;
                num /= prime[j];
            }
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        gcdCount[i] = totalCount[i] / N;
    }
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 0; j < gcdCount[i]; j++) {
            ans *= prime[i];
        }
        for (int j = 0; j < N; j++) {
            if (cnt[j][i] < gcdCount[i]) {
                idx += gcdCount[i] - cnt[j][i];
            }
        }
    }
    cout << ans << ' ' << idx << endl;
    return 0;
}