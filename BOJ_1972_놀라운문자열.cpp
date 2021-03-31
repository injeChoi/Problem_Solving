#include <bits/stdc++.h>
using namespace std;

string input, tmp;
set<string> ssang;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isSurprising() {
    for (int i = 1; i < input.length(); i++) {
        ssang.clear();
        for (int j = 0; j < input.length(); j++) {
            if (i + j < input.length()) {
                tmp = input[j];
                tmp += input[i+j];
                auto res = ssang.insert(tmp);
                if (!res.second) {
                    return false;
                }
            }
            else 
                break;
        }
    }
    
    return true;
}

int main(int argc, char const *argv[]) {
    init();

    while (1) {
        cin >> input;
        if (input == "*") 
            break;
        
        if (isSurprising()) 
            cout << input << " is surprising." << endl;
        else
            cout << input << " is NOT surprising." << endl;
    }
    return 0;
}