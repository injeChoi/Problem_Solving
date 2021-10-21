#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> positive, negative;
int answer, zero;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(int &a, int &b) {
    return a > b;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (n > 0) {
            positive.push_back(n);
        }
        else if (n < 0) {
            negative.push_back(n);
        }
        else {
            zero++;
        }
    }
    sort(positive.begin(), positive.end(), cmp);
    sort(negative.begin(), negative.end());
    if (zero > 0 && negative.size() % 2 == 1) {
        negative.pop_back();
    } 
    for (int i = 0; i < positive.size(); i++) {
        if (positive[i] == 1) {
            answer += 1;
        }
        else if (positive[i+1] == 1) {
            answer += positive[i] + positive[i+1];
            i++;
        }
        else {
            answer += positive[i] * positive[i+1];
            i++;
        }
    }
    if (positive.size() % 2 == 1 && positive.back() != 1) {
        answer += positive.back();
    }
    for (int i = 0; i < negative.size(); i += 2) {
        if (i+1 >= negative.size()) {
            break;
        }
        answer += negative[i] * negative[i+1];
    }
    if (negative.size() % 2 == 1) {
        answer += negative.back();
    }
    cout << answer << '\n';
    return 0;
}