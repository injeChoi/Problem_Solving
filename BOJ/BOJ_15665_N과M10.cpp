#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8], answer[8];
bool visited[8];

void recu(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << ' ';
        }
        cout << endl;
        return;
    }
    int prev = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (k >= 0 && answer[k-1] <= num[i]) {
                if (prev != num[i]) {   // 이 전에 사용한 값 중복해서 안 쓰게 세팅 
                    answer[k] = num[i];
                    prev = num[i];
                    visited[i] = true;
                    recu(k + 1);
                    visited[i] = false;
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);
    recu(0);
    return 0;
}