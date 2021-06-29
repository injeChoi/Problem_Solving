#include <bits/stdc++.h>
using namespace std;

int phone[4][3];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int BFS(int i, int j, int target) {
    bool visited[4][3] = {0};
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    int distance = 0;

    if (phone[i][j] == target) {
        return distance;
    }

    while (!q.empty()) {
        int y = q.front().first; // y 축
        int x = q.front().second;// x 축 
        q.pop();
        distance++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // new x 축
            int ny = y + dy[i]; // new y 축 

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 4 && !visited[ny][nx]) { // 이 조건에 충족하면 범위 내부 라는 뜻 
                if (phone[ny][nx] == target) { // 종료 조건 
                    return distance;
                }
                else {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    return distance;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int idx = 1;
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) 
            phone[i][j] = idx++;
    }
    phone[3][0] = -1;
    phone[3][1] = 0;
    phone[3][2] = -1;
    string currentHand = (hand == "left") ? "L" : "R";
    int currentLeft = -1, currentRight = -1;

    for (int idx = 0; idx < numbers.size(); idx++) {
        if (numbers[idx] == 1 || numbers[idx] == 4 || numbers[idx] == 7) {
            answer += "L";
            currentLeft = numbers[idx];
        }
        else if (numbers[idx] == 3 || numbers[idx] == 6 || numbers[idx] == 9) {
            answer += "R";
            currentRight = numbers[idx];
        }
        else {  // 중간 열 숫자 누를 때 
            int leftCnt, rightCnt;
            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 3; x++) {
                    if (phone[y][x] == currentLeft) {
                        leftCnt = BFS(y, x, numbers[idx]); 
                    }
                    else if (phone[y][x] == currentRight) {
                        rightCnt = BFS(y, x, numbers[idx]);
                    }
                }
            }
            if (leftCnt == rightCnt) {
                answer += currentHand;
                if (currentHand == "R") {
                    currentRight = numbers[idx];
                }
                else {
                    currentLeft = numbers[idx];
                }
            }
            else if (leftCnt > rightCnt) {
                answer += "R";
                currentRight = numbers[idx];
            }
            else {
                answer += "L";
                currentLeft = numbers[idx];
            }
        }
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    //freopen("input.txt", "r", stdin);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> numbers(10, 0);
    for (int i = 0; i < 10; i++) {
        numbers[i] = arr[i];
    }
    string hand = "right";
    string ans = solution(numbers, hand);
    cout << ans << endl;

    return 0;
}