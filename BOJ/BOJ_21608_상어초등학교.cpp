#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, MAX, ans;
int board[21][21];
int favorite[21][21];
bool visited[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> student, X, Y;
vector<vector<int>> prefer(21);
bool isEven;
vector<pii> dupBlank;
void firstCondition(int);
void secondCondition(int);
void thirdCondition(int);

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(pii &a, pii &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void firstCondition(int idx) {
    int dup = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (favorite[i][j] == MAX) {
                dup++;
                Y.push_back(i); // MAX값인 좌표 저장 
                X.push_back(j);
            }
        }
    }
    if (dup > 1) {  // 인접한 곳에 좋아하는 친구가 동률일 경우 
        secondCondition(idx);
    }
    else if (dup == 1) {
        visited[Y[0]][X[0]] = true;
        board[Y[0]][X[0]] = idx;
    }
    else {  // 내가 좋아하는 친구가 아직 자리 배정이 안 됐을 경우 
        thirdCondition(idx);
    }
}

void secondCondition(int idx) {
    int blankMAX = 0, newX = 0, newY = 0;
    for (int t = 0; t < Y.size(); t++) {
        int blank = 0;
        int y = Y[t];
        int x = X[t];
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 < ny && ny <= N && 0 < nx && nx <= N && !visited[ny][nx]) {
                blank++;
            }
        }
        if (blank > blankMAX) {
            blankMAX = blank;
            newX = x;
            newY = y;
            dupBlank.clear();
            dupBlank.push_back({newY, newX});
        }
        else if (blank == blankMAX) {
            dupBlank.push_back({newY, newX});
        }
    }
    if (dupBlank.size() > 1) {
        thirdCondition(idx);
        return;
    }
    visited[newY][newX] = true;
    board[newY][newX] = idx;
}

void thirdCondition(int idx) {
    sort(dupBlank.begin(), dupBlank.end(), cmp);
    int ny = dupBlank[0].first;
    int nx = dupBlank[0].second;
    visited[ny][nx] = true;
    board[ny][nx] = idx;
}

void findFavorite(int idx) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            favorite[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 < ny && ny <= N && 0 < nx && nx <= N) {
                        for (int p = 0; p < prefer[idx].size(); p++) {
                            if (board[ny][nx] == prefer[idx][p]) {
                                cnt++;
                            }
                        }
                    }
                }
                MAX = max(MAX, cnt);
                if (cnt != 0) {
                    favorite[i][j] = cnt;
                }
            }
        }
    }
}

void getAnswer(int idx, int i, int j) {
    int cnt = 0;
    for (int q = 0; q < 4; q++) {
        int ny = i + dy[q];
        int nx = j + dx[q];
        if (0 < ny && ny <= N && 0 < nx && nx <= N) {
            for (int p = 0; p < prefer[idx].size(); p++) {
                if (board[ny][nx] == prefer[idx][p]) {
                    cnt++;
                }
            }
        }
    }
    if (cnt > 1) {
        ans += pow(10, cnt-1);
    }
    else if (cnt == 1) {
        ans += 1;
    }
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    if (N % 2 == 0) {
        isEven = true;
    }
    for (int i = 0; i < N*N; i++) {
        int st; cin >> st;
        student.push_back(st);
        for (int j = 0; j < 4; j++) {
            int num; cin >> num;
            prefer[st].push_back(num);
        }
    }
    if (isEven) {
        board[N/2][N/2] = student[0];
        visited[N/2][N/2] = true;
    }
    else {
        board[N/2+1][N/2+1] = student[0];
        visited[N/2+1][N/2+1] = true;
    }
    for (int i = 1; i < N*N; i++) {
        int idx = student[i];
        findFavorite(idx);
        firstCondition(idx);
        MAX = 0;
        X.clear(); Y.clear();
        dupBlank.clear();
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int idx = board[i][j];
            getAnswer(idx, i, j);
        }
    }
    cout << ans << endl;
    return 0;
}