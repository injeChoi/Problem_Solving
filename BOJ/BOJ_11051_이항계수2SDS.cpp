#include <cstdio>
using namespace std;

int cache[1001][1001];

int nCr(int n, int r) {
    if (r == 0) {
        return 1;
    }
    if (n < r) {
        return 0;
    }
    if (n < 0 || 1000 < n || r < 0 || 1000 < r) 
        return 0;

    if (cache[n][r] != -1) {
        return cache[n][r];
    }

    int tmp = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % 10007;
    cache[n][r] = tmp;
    return cache[n][r];
}

int main() {
    for (int i = 0 ; i <= 1000 ; i++) {
        for (int j = 0 ; j <= 1000 ; j++) {
            cache[i][j] = -1;
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d", nCr(n, k));
}