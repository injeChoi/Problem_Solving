#include <bits/stdc++.h>
using namespace std;

int N, cnt;
vector<string> input;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool Checker(int idx1, int idx2) {
    int word1[27] = {0}, word2[27] = {0};
    int len = input[idx1].length();

    for (int i = 0; i < len; i++) {
        int num1 = input[idx1][i] - 96;
        int num2 = input[idx2][i] - 96;

        if (!word1[num1] && !word2[num2]) {
            word1[num1] = num2;
            word2[num2] = num1;
        }
        else if (word1[num1] != num2)
            return false;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    while (N--) {
        string tmp; cin >> tmp;
        input.push_back(tmp);
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = i+1; j < input.size(); j++) {
            if (input[i].length() == input[j].length()) {
                bool flag = Checker(i, j);
                if (flag)
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}