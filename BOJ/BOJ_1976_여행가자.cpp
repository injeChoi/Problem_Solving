#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1001];
bool path[201][201];
vector<int> p;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int findParent(int x) {
    if (parent[x] == x) {
        return x;        
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int  b) {
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

    for (int i = 1; i <= N; i++) 
        parent[i] = i;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            cin >> path[i][j];

    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            if (path[i][j]) 
                unionParent(i, j);

    for (int i = 1; i <= M; i++) {
        int num;
        cin >> num;
        p.push_back(findParent(num));
    }
    for (int i = 0; i < p.size()-1; i++) {
        if (p[i] != p[i+1]) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}