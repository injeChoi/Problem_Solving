#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

bool isPrime[MAX];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void sosu() {
    for (int i = 2; i < MAX; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < sqrt(MAX); i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

string to_K_nary(int n, int k) {
    string tmp = "";
    while (n > 0) {
        int mod = n % k;
        n = n / k;
        tmp += to_string(mod);
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int solution(int n, int k) {
    sosu();
    int answer = 0, idx = 0;
    string str = to_K_nary(n, k);
    cout << str << endl;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            string tmp = str.substr(idx, i - idx);
            if (tmp != "") {
                idx = i+1;
                int strNum = stoi(tmp);
                if (isPrime[strNum]) {
                    answer++;
                }
            }
        }
        if (idx <= i && i == str.length() - 1) {
            string tmp = str.substr(idx, str.length());
            int strNum = stoi(tmp);
            if (isPrime[strNum]) {
                answer++;
            }
        }
    }
    cout << "answer: " << answer << endl; 
    return answer;
}

int main(int argc, char const *argv[]) {
    init(); 
    solution(1000000, 6);
    return 0;
}