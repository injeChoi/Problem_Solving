#include <bits/stdc++.h>
using namespace std;

string tmp, input;
char filtered[200001], look[200001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> tmp >> look;

    for (int i = 0; i < tmp.size(); i++) 
        if (!isdigit(tmp[i])) 
            input += tmp[i];

    for (int i = 0; i < input.size(); i++) 
        filtered[i] = input[i];
    
    char *ptr = strstr(filtered, look);

    ptr != NULL ? cout << 1 << endl : cout << 0 << endl;
    return 0;
}