#include <bits/stdc++.h>
using namespace std;

int X, cnt, stick = 64, sum;
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> X;

    while (stick >= 1) {
        v.push_back(stick);
        stick /= 2;
    }
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) 
        if (X == v[i]) {
            cout << 1 << endl;
            return 0;
        }

    while (X != 0) {
        for (int i = 0; i < v.size(); i++)
            if (X < v[i]) {
                X -= v[i-1];
                break;
            }
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}