#include <bits/stdc++.h>
using namespace std;

int K, N, idx;
char tmp;
string input, output, ans;
vector<string> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> K >> N >> input;
    output = input;
    sort(input.begin(), input.end());
    
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        if (str[0] == '?')
            idx = i;
        v.push_back(str);
    }
    
    for (int i = 0; i < idx; i++) 
        for (int j = 0; j < v[i].length(); j++) 
            if (v[i][j] == '-') {
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }

    for (int i = N-1; i > idx; i--) 
        for (int j = 0; j < v[i].length(); j++) 
            if (v[i][j] == '-') {
                tmp = output[j];
                output[j] = output[j+1];
                output[j+1] = tmp;
            }

    for (int i = 0; i < input.length()-1; i++) {
        if (input[i] != output[i]) {
            if (input[i] == output[i+1]) 
                i++;
            else {
                for (int i = 0; i < K-1; i++) 
                    cout << 'x';
                cout << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != output[i]) {
            ans += "-*";
            i++;
        }
        else 
            ans += '*';
    }

    for (int i = 0; i < K-1; i++) 
        cout << ans[i];
    cout << endl;

    return 0;
}