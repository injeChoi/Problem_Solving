// 두번째 ==> 숫자를 그대로이용하는 방법 
// ABCD : 1000 * A + 100 * B + 10 * C + D
// GCD : 100 * G + 10 * C + D
// EFABC : 10000 * E + 1000 * F + 100 * A + 10 * B + C
// ----------------------------------------------------
// 1100 * A + 110 * B + 21 * C + 2 * D + 10000 * E + 1000 * F + 100 * G

#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pci;

int N, ans, idx = 9;
unordered_map<char, int> hash_map;
vector<string> input;

bool compare(const pair<char, int> &a, const pair<char, int> &b) {
    if (a.second == b.second) 
        return a.first > b.first;
	return a.second > b.second;
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        reverse(str.begin(), str.end());
        input.push_back(str);
    }
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            char c = input[i][j];
            if (hash_map.count(c) != 0) {
                hash_map[c] += pow(10, j);
            }
            else {
                hash_map[c] = pow(10, j);
            }
        }
    }
    vector<pci> v(hash_map.begin(), hash_map.end());
    sort(v.begin(), v.end(), compare);

    for (auto iter : v) {
        ans += iter.second * idx--;
    }
    cout << ans << endl;
    return 0;
}