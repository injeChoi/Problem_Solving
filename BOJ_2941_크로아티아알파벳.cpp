#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    vector<string> croatian = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int idx;
    string str;
    cin >> str;
    for(int i = 0; i < croatian.size(); i++)
    {
        while(1){
            idx = str.find(croatian[i]);
            if(idx == string::npos) // croatian 알파벳을 찾을 수 없으면 종료 
                break;
            str.replace(idx,croatian[i].length(), "#"); // croatian 알파벳이면 #으로 대체 
        }
    }
    cout << str.length() << endl;
    return 0;
}