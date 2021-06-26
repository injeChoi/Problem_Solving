#include <bits/stdc++.h>
using namespace std;

int N, ans, testcase;
vector<int> camel;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();

    cin >> testcase;
    for (int c = 1; c <= testcase; c++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            camel.push_back(num);
        }

        sort(camel.begin(), camel.end());

        if (N == 1) {
            ans += camel[0];
        }
        else if (N == 2) {
            ans += camel[1];
        }
        else {
            if (N % 2 == 0) {
                bool check = false;
                if (camel[1] == camel[2]) {
                    check = true;
                }
                if (!check) {
                    while (camel.size() >= 3) {
                        ans += camel[0] + camel[1]; 
                        ans += camel.back() + camel[1];
                        camel.pop_back();
                        camel.pop_back();
                    }
                    ans += camel[1];
                }
                else {
                    if (N > 4 && ((camel[2] == camel[3]) && (camel[3] == camel[4]))) {
                        while (camel.size() > 2) {
                            ans += camel[0] + camel.back();
                            camel.pop_back();
                        }
                        ans += camel[1];
                    }
                    else {
                        while (camel.size() >= 5) { // 원소 개수가 5개 일 때 까진 기존처럼 진행 
                            ans += camel[0] + camel[1]; 
                            ans += camel.back() + camel[1];
                            camel.pop_back();
                            camel.pop_back();
                        }
                        while (camel.size() > 2) {
                            ans += camel[0] + camel.back();
                            camel.pop_back();
                        }
                        ans += camel[1];
                    }
                }
            }
            else {
                bool check = false;
                if (camel[1] == camel[2] && camel[2] == camel[3]) {
                    check = true;
                }
                if (!check) {
                    while (camel.size() > 3) {
                        ans += camel[0] + camel[1]; 
                        ans += camel.back() + camel[1];
                        camel.pop_back();
                        camel.pop_back();
                    }
                    ans += camel[0] + camel[1] + camel.back();
                }
                else {
                    while (camel.size() > 2) {
                        ans += camel.back() + camel[0];
                        camel.pop_back();
                    }
                    ans += camel[1];
                }
            }
        }
        cout << "#" << c << " " << ans << endl;
        camel.clear();
        ans = 0;
    }
    return 0;
}