#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
int A[51][51];
int B[51][51];

bool compare() {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (A[i][j] != B[i][j]) 
                return false;
    return true;
}

void convert(int y, int x) {
    for (int i = y; i < y+3; i++) {
        for (int j = x; j < x+3; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            scanf("%1d", &A[i][j]);

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            scanf("%1d", &B[i][j]);

    for (int i = 0; i < N-2; i++) {
        for (int j = 0; j < M-2; j++) {
            if (A[i][j] != B[i][j]) {
                cnt++;
                convert(i, j);
            }
        }
    }
    if (compare())
        cout << cnt << '\n';
    else
        cout << -1 << '\n';
    return 0;
}