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
    //freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int candidate; cin >> candidate;
        int total = 0, winner = 0, idx = 0, cnt = 0;;
        bool flag = false;
        vector<int> vote;
        for (int i = 0; i < candidate; i++) {
            int num; cin >> num;
            total += num;
            if (num > winner) {
                winner = num;
                idx = i;
            }
            vote.push_back(num);
        }
        for (int i = 0; i < candidate; i++) {
            if (winner == vote[i]) 
                cnt++;
            if (cnt > 1) {
                flag = true;
                cout << "no winner" << endl;
                break;
            }
        }
        if (!flag) {
            if (total / 2 < vote[idx]) 
                cout << "majority winner " << idx + 1 << endl;
            else
                cout << "minority winner " << idx + 1 << endl; 
        }
    }
    return 0;
}
