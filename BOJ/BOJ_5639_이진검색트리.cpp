#include <bits/stdc++.h>
using namespace std;

vector<int> pre;

void recu(int s, int e) {
    if (s == e) {
        cout << pre[s] << endl; // 노드 출력 
        return;
    }
    else if (s > e) {
        return;
    }
    else {
        int where = s + 1;      // root의 자식 
        while (where <= e) {    // where가 root보다 커지는 순간 (root의 오른쪽 자식 발견) 찾기
            if (pre[where] > pre[s]) {
                break;
            }
            else {
                where++;
            }
        }
        // 왼쪽 자식
        recu(s+1, where-1);
        // 오른쪽 자식
        recu(where, e);
        cout << pre[s] << endl; //루트 출력 
    }
}

int main(int argc, char const *argv[]) {
    int num;
    while (cin >> num) {
        pre.push_back(num);
    }
    recu(0, pre.size()-1);
    return 0;
}