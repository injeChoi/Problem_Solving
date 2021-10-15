#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, MAX;
int arr[101];
bool visited[101];
vector<int> result;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// 사이클이 형성되는 것 찾기 
void DFS(int current, int start) {
    if (visited[current]) {
        if (current == start) {
            result.push_back(start);
        }
    }
    else {
        visited[current] = true;
        DFS(arr[current], start);
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    // 1번부터 순서대로 사이클 찾기 
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        DFS(i, i);
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}