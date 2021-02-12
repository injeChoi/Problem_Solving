#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();

    while (1) {
        int n1, n2;
        long long result = 1;
        cin >> n1 >> n2;

        n2 = min(n2, n1 - n2);

        if (n1 == 0 && n2 == 0) break;
        
        for (int i = 1; i <= n2; i++) {
            result *= n1--;
            result /= i;
        }
        cout << result << endl;
    }

    return 0;
}