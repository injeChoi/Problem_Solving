#include <bits/stdc++.h>
using namespace std;

// a c n i t 는 이미 배우는 걸로 시작 
bool alphabet[26] = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
vector<string> word;
int N, K, ans;

int solution() {
    int count = 0;  // 읽을 수 있는 단어 개수 

    for (int i = 0; i < word.size(); i++) {
        bool readable = true;
        for (int j = 0; j < word[i].length(); j++) {
            if (alphabet[word[i][j] - 'a'] == false) {   // 배운적 없는 문자면 읽을 수 없는 단어 
                readable = false;
                break;
            }
        }
        if (readable) {
            count++;
        }
    }
    return count;
}

void DFS(int idx, int cnt) {
    if (cnt == K) { // DFS 반환(종료) 조건, K개 문자 배웠을 떄 알 수 있는 최대 단어 개수 최신화 
        ans = max(ans , solution());
        return;
    }
    for (int i = idx; i < 26; i++) {  // 알파벳 조합 만들기 시작 
        if (!alphabet[i]) {
            alphabet[i] = true;     // 조합에 들어온 문자는 사용 금지하게 세팅 
            DFS(i, cnt+1);          // 만들어둔 조합으로 계산 끝났으면 
            alphabet[i] = false;    // 새로운 조합 만들게 세팅 풀어주기 
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> K;
    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }
    K -= 5; // 이미 배운 단어 개수 제거, 새로 배우는 것만 카운트 

    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        word.push_back(str);
    }
    DFS(0, 0);
    cout << ans << endl;
    return 0;
}