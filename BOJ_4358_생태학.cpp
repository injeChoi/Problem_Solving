#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    map<string, double> treeMap;
    map<string, double>::iterator iter;
    string treeName;
    int total = 0;

    while(getline(cin, treeName)) { // EOF를 입력받기 전 까지 계속 입력 받고 treeName 변수에 저장
        total++;
        if (treeMap.find(treeName) != treeMap.end())  // find로 못찾으면 map.end()와 같은 값을 리턴한다. 
            treeMap[treeName]++;
        
        else
            treeMap[treeName] = 1;
    }

    cout << fixed; // 소수점 이후로 (이게 없으면 소수점 이전 자리 수 까지 포함해서 4자리만 출력 됨)
    cout.precision(4); // 4자리만 출력 (이후로는 반올림)

    for (iter = treeMap.begin(); iter != treeMap.end(); iter++) {
        string tree = iter->first;
        double percentage = iter->second / total * 100;
        cout << tree << " " << percentage << endl;
    }

    return 0;
}