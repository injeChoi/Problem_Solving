#include <bits/stdc++.h>
using namespace std;

vector<string> str;
string s;

int main(int argc, char const *argv[]) {
    while(getline(cin, s)) 
        str.push_back(s);

    for (int i = 0; i < str.size(); i++) 
        cout << str[i] << endl;
        
    return 0;
}