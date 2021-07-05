#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000001
#define MIN -1000000001

vector<string> command;
vector<long long> nums;
stack<long long> st;
long long N, tmp1, tmp2;

void input() {
    command.clear();
    nums.clear();
    while (1) {
        string input = "";
        getline(cin, input);
        if (input == "QUIT") {
            exit(0);
        }
        else if (input != "END") {
            command.push_back(input);
        }
        else if (input == "END") {
            break;
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }
}

void getNum() {
    tmp1 = st.top();
    st.pop();
    tmp2 = st.top();
    st.pop();
}

int solution() {
    for (int c = 0; c < command.size(); c++) {
        if (command[c][0] == 'N') { // NUM
            int idx = command[c].find(' ');
            string tmp = "";
            for (int i = idx+1; i < command[c].length(); i++) {
                tmp += command[c][i];
            }
            int n = atoi(tmp.c_str());
            st.push(n);
        }
        else if (command[c] == "POP") {
            if (!st.empty()) {
                st.pop();
            }
            else {
                return -1;
            }
        }
        else if (command[c] == "INV") {
            if (st.empty()) {
                return -1;
            }
            st.top() = -(st.top());
        }
        else if (command[c] == "DUP") {
            if (st.empty()) {
                return -1;
            }
            st.push(st.top());
        }
        else if (command[c] == "SWP") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            st.push(tmp1);
            st.push(tmp2);
        }
        else if (command[c] == "ADD") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            if (tmp1 + tmp2 >= MAX) {
                return -1;
            }
            st.push(tmp1 + tmp2);
        }
        else if (command[c] == "SUB") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            if (tmp2 - tmp1 >= MAX || tmp2 - tmp1 <= MIN) {
                return -1;
            }
            st.push(tmp2 - tmp1);
        }
        else if (command[c] == "MUL") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            long long mul = tmp1 * tmp2;
            if (abs(mul) >= MAX) {
                return -1;
            }
            long long ans = tmp1 * tmp2;
            st.push(ans);
        }
        else if (command[c] == "DIV") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            if (tmp1 == 0) {
                return -1;
            }
            int flag = 0;
            if (tmp1 < 0) {
                flag++;
            }
            if (tmp2 < 0) {
                flag++;
            }
            long long div = abs(tmp2 / tmp1);
            if (flag == 1) {
                st.push(-div);
            }
            else {
                st.push(div);
            }
        }
        else if (command[c] == "MOD") {
            if (st.size() < 2) {
                return -1;
            }
            getNum();
            if (tmp1 == 0) {
                return -1;
            }
            long long mod = tmp2 % tmp1;
            st.push(mod);
        }
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    while (1) {
        input();
        for (int n = 0; n < nums.size(); n++) {
            st.push(nums[n]);   // 최초 값 세팅 
            int ret = solution();
            if (ret == -1) {
                cout << "ERROR" << endl;
            }
            else if (st.size() > 1 || st.size() == 0) {
                cout << "ERROR" << endl;
            }
            else {
                cout << st.top() << endl;
            }
            while (!st.empty()) {
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}