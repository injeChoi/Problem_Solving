#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> small;
vector<char> big;
vector<char> cat;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(int loop) {
    while(loop--)
        for (int idx = 0; idx < cat.size(); idx++) {
            if (islower(cat[idx]) != 0 && isupper(cat[idx+1]) != 0) {
                char tmp;
                tmp = cat[idx];
                cat[idx] = cat[idx+1];
                cat[idx+1] = tmp;
                idx++;
            }
        }
}
int main() {
    init();
    int first, last; 
    cin >> first >> last;
    char temp;
    int time;

    for (int i = 0; i < first; i++) {
        char c; cin >> c;
        small.push_back(tolower(c));
    }

    reverse(small.begin(), small.end());

    for (int i = 0; i < last; i++) {
        char c; cin >> c;
        big.push_back(c);
    }
    cat.insert( cat.end(), small.begin(), small.end() );
    cat.insert( cat.end(), big.begin(), big.end() );

    cin >> time;

    if (time >= cat.size() - 1) 
        solve(cat.size() - 1);
    else 
        solve(time);
    
    for (int i = 0; i < cat.size(); i++) {
        if (islower(cat[i]) != 0)
            cat[i] = cat[i] - 32;
        cout << cat[i];
    }

    return 0;
}