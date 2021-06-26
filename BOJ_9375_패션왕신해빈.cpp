/*
조합에 관한 수학적 지식이 요구됐던 문제
옷 이름과 옷 종류가 주어진다.
같은 종류의 옷은 겹치게 입지 못한다.
해당 종류의 옷을 입지 않을 수도 있다.
옷을 아예 안 입는 경우는 없다. 
A, B 종류의 옷이 있다고 할 때, 
A 옷의 개수는 2개(안 입는다 하면 3개), B 옷의 개수는 1개(안 입는다 하면 2개) 있다고 하면 
같은 종류의 옷은 겹치게 입지 못하고 알몸이 아닌 상태의 경우의 수는 3C1 * 2C1 -1 
쉽게 말해 알몸일 때 빼고, 아무거나 하나라도 걸쳐입은 경우의 수 구하는 것.
*/
#include <bits/stdc++.h>
using namespace std;

int T;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> T;

    while (T--) {
        int clothesNum; cin >> clothesNum;
        map<string, int> clothesInfo;
        map<string, int>::iterator iter;
        int combination = 1;

        for (int i = 0; i < clothesNum; i++) {
            string name, category;
            cin >> name >> category; // name은 사용하지 않는다. 
            if (clothesInfo.find(category) == clothesInfo.end()) // map 안에 없는거면 새로 추가 
                clothesInfo.insert({category, 1});
            
            else 
                clothesInfo[category]++;
        }
        for (iter = clothesInfo.begin(); iter != clothesInfo.end(); iter++) 
            combination *= iter->second + 1; // +1은 해당 종류 옷을 안 입는걸 경우의 수로 추가하는 것 
        
        cout << combination - 1 << endl; // -1은 알몸인 상태는 제외하는 것
    }

    return 0;
}