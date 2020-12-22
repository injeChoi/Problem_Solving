#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();

    int N; cin >> N; 
    vector<int> v(21);

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    v[4] = 7;

    for (int i = 5; i <= N; i++) {
        v[i] = v[i-1] * 2;
        if (i % 2 == 0) 
            v[i] -= v[i-4] + v[i-5];
    }

    cout << v[N] << endl; 
    return 0;
}
