#include <bits/stdc++.h>
using namespace std;

int T, Start, End;
bool isPrime[10000];
int visited[10000];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void SOE() {
    for (int i = 2; i*i < 10000; i++) 
        for (int j = i*i; j < 10000; j+=i) 
            isPrime[j] = false;
}

void BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            string str = to_string(x);

            for (int j = 0; j < 10; j++) {
                str[i] = j + '0';
                int num = stoi(str);
                if (num >= 1000 && isPrime[num] && !visited[num]) {
                    visited[num] = visited[x] + 1;
                    q.push(num);
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    init();
    memset(isPrime, 1, sizeof(isPrime));
    SOE();
    cin >> T;
    
    while (T--) {
        memset(visited, 0, sizeof(visited));
        cin >> Start >> End;

        BFS(Start);

        if (visited[End]) cout << visited[End] - 1 << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}