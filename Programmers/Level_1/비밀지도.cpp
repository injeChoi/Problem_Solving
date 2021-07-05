#include <bits/stdc++.h>
using namespace std;

string toBinary(int num) {
    string ret = "";
    while (num != 0) {
        ret += to_string(num%2);
        num /= 2;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer, a1, a2;
    for (int i = 0; i < arr1.size(); i++) {
        string ret = toBinary(arr1[i]);
        int gap = n - ret.size();
        for (int j = 0; j < gap; j++) {
            ret += "0";
        }
        reverse(ret.begin(), ret.end());
        a1.push_back(ret);
    }
    for (int i = 0; i < arr2.size(); i++) {
        string ret = toBinary(arr2[i]);
        int gap = n - ret.size();
        for (int j = 0; j < gap; j++) {
            ret += "0";
        }
        reverse(ret.begin(), ret.end());
        a2.push_back(ret);
    }
    for (int i = 0; i < arr1.size(); i++) {
        string str1 = a1[i];
        string str2 = a2[i];
        string ans = "";
        for (int j = 0; j < str1.length(); j++) {
            if (str1[j] == '1' || str2[j] == '1') {
                ans += "#";
            }
            else if (str1[j] == '0' && str2[j] == '0') {
                ans += " "; 
            }
        }
        answer.push_back(ans);
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    solution(5, arr1, arr2);
    return 0;
}