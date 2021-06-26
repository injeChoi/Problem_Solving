#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    while(1) {
        string str;
        stack<char> s;
        getline(cin, str);

        if (str.length() == 1 && str[0] == '.') 
            break;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') 
                s.push(str[i]);
            
            if (!s.empty() && str[i] == ')') {
                if (s.top() == '(') s.pop();
                else break;
            }
            else if (!s.empty() && str[i] == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else break;
            }
            else if (s.empty() && str[i] == ')' || s.empty() && str[i] == ']') 
                s.push('!');
        }
        if (s.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}