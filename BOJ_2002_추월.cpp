#include <bits/stdc++.h>
using namespace std;

map<string, int> in;
vector<int> out;
int N, cnt;
string str;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        in.insert({str, i});
    }
    for (int i = 0; i < N; i++) {
        cin >> str;
        out.push_back(in[str]);
    }

    for (int i = 0; i < N-1; i++) 
        for (int j = i + 1; j < N; j++) 
            if (out[i] > out[j]) {
                cnt++;
                break;
            }

    cout << cnt << endl;
    return 0;
}