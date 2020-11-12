#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(string word) {
    bool alphabet[26] = {false};

    for (int i = 0; i < word.length(); i++) {
        if (alphabet[word[i]-'a']) 
            return false;

        else {
            alphabet[word[i]-'a'] = true;
            char tmp = word[i];
            while (tmp == word[++i]) {
                continue;
            }
            i--;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    init();

    int N; 
    cin >> N;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        if (check(str) == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
