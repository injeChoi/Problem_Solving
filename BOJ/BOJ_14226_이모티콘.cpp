#include <bits/stdc++.h>
using namespace std;

int S;
bool visited[1001][1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int BFS() {
    queue<tuple<int, int, int> > q;
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        int display, clipboard, cnt;
        tie(display, clipboard, cnt) = q.front();
        q.pop();

        if (display == S) 
            return cnt;
        
        if (0 < display && display < 1001) {
            if (!visited[display][display]) {
                visited[display][display] = true;
                q.push({display, display, cnt+1});
            }
            if (0 < clipboard && display + clipboard < 1001) {
                if (!visited[display+clipboard][clipboard]) {
                    visited[display+clipboard][clipboard] = true;
                    q.push({display+clipboard, clipboard, cnt+1});
                }
            }
            if (!visited[display-1][clipboard]) {
                visited[display-1][clipboard] = true;
                q.push({display-1, clipboard, cnt+1});
            }
        }        
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    init();
    cin >> S;
    cout << BFS() << endl;
    return 0;
}