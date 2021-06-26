#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int sum, A, B, cnt = 1;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            arr[cnt++] = i;
            if (cnt == 1001) {
                i = 1001;
                break;
            }
        }
    }

    cin >> A >> B;
    for (int i = A; i <= B; i++) 
        sum += arr[i];
    
    cout << sum << endl;
    return 0;
}