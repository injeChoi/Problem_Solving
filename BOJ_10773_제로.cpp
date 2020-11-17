#include <iostream>
#include <stack>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int K; cin >> K;
    int sum = 0;
    stack<int> s;

    while (K--) {
        int num; cin >> num;
        if (num == 0) 
            s.pop();
        else 
            s.push(num);
    }

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;
    return 0;
}
