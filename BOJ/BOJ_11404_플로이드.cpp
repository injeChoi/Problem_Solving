#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M;
int city[101][101];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                city[i][j] = 0;
            }
            else {
                city[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == INF) 
                cout << 0 << ' ';
			else 
                cout << city[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}