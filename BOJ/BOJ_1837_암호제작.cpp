#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

string P;
int K;
bool isPrime[MAX];
vector<int> prime;

void SOE() {
    for (int i = 2; i <= MAX; i++)  // 초기화 
        isPrime[i] = true;

    for (int i = 2; i <= sqrt(MAX); i++) {
        if(isPrime[i] == 0)
            continue;
        else {
            for (int j = i+i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> P >> K;
    SOE();
    for (int i = 0; i < MAX; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
    // 소수 중 K 이하인 숫자들만 고려 
    for (int i = 0; i < prime.size() && prime[i] < K; i++) {
        int sum = 0;
        // 엄청 큰 숫자 P를 차츰차츰 증가시켜 나가면서 어느 부분에서 소수랑 나눠 떨어지는 부분이 있는지 검사 
        // 어떤 부분에서 나머지가 0으로 나눠떨어졌으면 그 다음 부분 부터 새로 또 어느 부분에서 나눠떨어지는 부분이 있는지 검사
        // 이렇게 해야 int 범위 내에서 조사가 가능해진다 (K는 int범위 내부이므로)
        for (int j = 0; j < P.length(); j++) {
            sum = (sum * 10 + (P[j]-'0')) % prime[i];
        }
        if (sum == 0) { // 나눠떨어진 부분이 생기면 BAD 출력 
            cout << "BAD " << prime[i] << endl;
            return 0;
        }
    }
    cout << "GOOD" << endl;
    return 0;
}