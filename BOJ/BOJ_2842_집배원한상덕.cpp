#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, cnt_k, y_post, x_post, h[50][50];
char village[50][51];
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> hCollect;

int BFS(int low, int high) {
    int cnt = 0;
    queue<pii> q;
    bool visited[50][50] = {0};
    q.push({y_post, x_post});
    visited[y_post][x_post] = true;
    // 우체국 위치가 low, high 범위 밖이면 예외 처리 
    if (h[y_post][x_post] < low || h[y_post][x_post] > high ) {
        return -1;
    }

    while (!q.empty() && cnt < cnt_k) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            if (h[ny][nx] < low || h[ny][nx] > high) {
                continue;
            }
            if (village[ny][nx] == 'K') {
                cnt++;
            }
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> village[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> h[i][j];
            hCollect.push_back(h[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (village[i][j] == 'K') {
                cnt_k++;
            }
            if (village[i][j] == 'P') {
                y_post = i;
                x_post = j;
            }
        }
    }
    sort(hCollect.begin(), hCollect.end());
    int ans = hCollect.back() - hCollect.front(); // 가장 큰 피로도 (상한선)

    for (int low = 0, high = 0; low < hCollect.size() && high < hCollect.size() && low <= high; ) {
        if (BFS(hCollect[low], hCollect[high]) == cnt_k) { // 현재 단계에서 답이 나오나? (모든 집 방문 했는지) 
            int tmp = hCollect[high] - hCollect[low];      // 현재 단계의 피로도 
            ans = min(ans, tmp);                           // 되면 답 교체하고 lower bound 증가해서 새로운 답이 있는지 찾아보기
            low++;
        }
        else { // 현재 단계의 higher bound에서 모든 집 방문이 안 되면 high 값 증가시켜보기 
            high++;
        }
    }
    cout << ans << endl;
    return 0;
}