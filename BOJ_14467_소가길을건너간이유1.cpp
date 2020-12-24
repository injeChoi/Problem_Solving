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
    int cowNum = 0, cnt = 0;
    bool pos = 0;
    int check[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    for (int i = 0; i < N; i++) {
        cin >> cowNum >> pos;

        if (check[cowNum] == -1) 
            check[cowNum] = pos;
        
        else if (check[cowNum] != pos && check[cowNum] != -1) {
            check[cowNum] = pos;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
