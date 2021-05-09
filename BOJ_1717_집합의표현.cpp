#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int findParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    // return findParent(parent[x]);
    return parent[x] = findParent(parent[x]); // 경로 압축 (메모이제이션)
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M;

    for (int i = 0; i <= 1000000; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        bool opt;
        int a, b;
        cin >> opt >> a >> b;

        if (opt == true) {
            if (findParent(a) == findParent(b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
        else {
            unionParent(a, b);
        }
    }

    return 0;
}