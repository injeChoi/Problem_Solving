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
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> v;
        string str; cin >> str;
        for (int i = 0; i < str.length(); i++) {
            int num = str[i] - '0';
            v.push_back(num);
        }   
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > 4) {
                v[i] = 0;
                v[i+1]++;
            }
            else 
                v[i] = 0;
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) 
            cout << v[i];
        cout << endl; 
    }
    return 0;
}