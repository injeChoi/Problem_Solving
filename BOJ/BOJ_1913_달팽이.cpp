#include <iostream>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int N; cin >> N;
    int dest; cin >> dest;
    int n = N, iter = N / 2, NS = N * N;
    int snail[N][N];
    int i = 0, j = 0, idx = 1;

    while (iter--) {
        for (i = i; i <= n-1; i++) 
            snail[i][j] = NS--;
        i--;
        
        for (j = j+1; j <= n-1; j++)
            snail[i][j] = NS--;
        j--;
        
        for (i = i-1; i >= idx-1; i--)
            snail[i][j] = NS--;
        i++;
        
        for (j = j-1; j >= idx; j--)
            snail[i][j] = NS--;
        j++;

        i++; idx++; n--;
    }

    snail[N/2][N/2] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cout << snail[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (snail[i][j] == dest) {
                cout << i+1 << " " << j+1 << endl;
                break;
            }

    return 0;
}
