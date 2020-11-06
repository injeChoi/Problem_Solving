/*
https://www.acmicpc.net/problem/14719
https://imnotabear.tistory.com/217
왼쪽에서 부터 오른쪽, 오른쪽에서 부터 왼쪽으로 제일 큰걸
찾아가는 방법이 제일 중요했다.
그리고 나서 찾은 값들 중 작은걸 택해서
내가 고른 열의 높이 값을 빼는게 주요했다. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int H, W, arr[1000];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    freopen("input.txt", "r", stdin);
    int left, right, cnt = 0;

    cin >> H >> W;

    for (int i = 1; i <= W; i++)
        cin >> arr[i];

    for (int i = 2; i < W; i++) {
        left = arr[i];
        right = arr[i];

        for (int j = 1; j < i; j++) 
            left = max(left, arr[j]);
        
        for (int j = i+1; j <= W; j++) 
            right = max(right, arr[j]);
        
        cnt += min(left, right) - arr[i];
    }
    cout << cnt << endl;

    return 0;
}
