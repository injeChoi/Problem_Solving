#include <bits/stdc++.h>
using namespace std;

string str, buffer;
vector<string> v;
int cnt;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fillZero() {
    if (buffer.length() < 5) {
        int bufLen = buffer.length();
        for (int i = 0; i < 4 - bufLen; i++)
            buffer = '0' + buffer;
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ':') 
            buffer += str[i];

        else if (str[i] == ':' && str[i+1] != ':') {
            fillZero();
            v.push_back(buffer);
            buffer.clear();
            cnt++;
        }
        else if (str[i] == ':' && str[i+1] == ':') {
            fillZero();
            v.push_back(buffer);
            cnt++;

            for (int j = i+1; j < str.length(); j++) 
                if (str[j] == ':') 
                    cnt++; 
   
            for (int j = 0; j < 7 - cnt; j++) 
                v.push_back("0000");
            
            buffer.clear();
        }
        if (i == str.length()-1 && str[i] != ':') {
            fillZero();
            v.push_back(buffer);
        }
    }

    for (int i = 0; i < v.size()-1; i++) 
        cout << v[i] << ":";
    cout << v.back() << endl;

    return 0;
}