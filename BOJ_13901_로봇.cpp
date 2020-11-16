#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int R, C; 
    int N; 
    int sr, sc;
    queue<int> q;
    int tmp, cnt = 0;

    cin >> R >> C;        //방의 크기
    bool visited[R][C];
    memset(visited, false, sizeof(visited));

    cin >> N;             //장애물 개수
    for (int i = 0; i < N; i++) {
        int br, bc;                 //장애물 위치
        cin >> br >> bc;    
        visited[br][bc] = true;
    }

    cin >> sr >> sc;     //로봇 시작 위치
    visited[sr][sc] = true;

    for (int i = 0; i < 4; i++) {
        int direction; cin >> direction;
        q.push(direction);
    }

    while(!q.empty()) {
        if (q.front() == 1) {
            if(sr-1 < 0 || visited[sr-1][sc] == true) {
                cnt++;
                if (cnt == 4) 
                    break;
                tmp = q.front();
                q.pop();
                q.push(tmp);
                continue;
            }
            while (visited[sr-1][sc] == false && sr-1 >= 0) { //장애물이나 왔던데가 아니면 진행
                visited[--sr][sc] = true;
            }
        }
        else if (q.front() == 2) {
            if(sr+1 >= R || visited[sr+1][sc] == true) {
                cnt++;
                if (cnt == 4) 
                    break;
                tmp = q.front();
                q.pop();
                q.push(tmp);
                continue;
            }
            while (visited[sr+1][sc] == false && sr+1 < R) { //장애물이나 왔던데가 아니면 진행
                visited[++sr][sc] = true;
            }
        }
        else if (q.front() == 3) {
            if(sc-1 < 0 || visited[sr][sc-1] == true) {
                cnt++;
                if (cnt == 4) 
                    break;
                tmp = q.front();
                q.pop();
                q.push(tmp);
                continue;
            }
            while (visited[sr][sc-1] == false && sc-1 >= 0) { //장애물이나 왔던데가 아니면 진행
                visited[sr][--sc] = true;
            }
        }
        else {
            if(sc+1 >= C || visited[sr][sc+1] == true) {
                cnt++;
                if (cnt == 4) 
                    break;
                tmp = q.front();
                q.pop();
                q.push(tmp);
                continue;
            } 
            while (visited[sr][sc+1] == false && sc+1 < C) { //장애물이나 왔던데가 아니면 진행
                visited[sr][++sc] = true;
            }
        }
        cnt = 0;
        tmp = q.front();
        q.pop();
        q.push(tmp);  
    }
    cout << sr << " " << sc << endl;
    return 0;
}
