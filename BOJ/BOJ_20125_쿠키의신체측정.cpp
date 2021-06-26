#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int N; cin >> N;
    bool head = false;
    pair<int, int> heart;
    int la = 0, ra = 0, b = 0, ll = 0, rl = 0;
    char tray[N][N];

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> tray[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tray[i][j] == '*' && head == false) { // 심장 위치 확인
                head = true;
                heart = make_pair(i + 1, j);
                cout << i + 2 << " " << j + 1 << endl;
            }
            else if (tray[i][j] == '*' && head == true) {
                if (i == heart.first && j < heart.second)  // 왼팔
                    la++;
                if (i == heart.first && j > heart.second)
                    ra++;
                if (i > heart.first && j == heart.second)
                    b++;
                if (i > heart.first && j == heart.second - 1)
                    ll++;
                if (i > heart.first && j == heart.second + 1)
                    rl++;
            }
        }
    }
    cout << la << " " << ra << " " << b << " " << ll << " " << rl;
    return 0;
}
