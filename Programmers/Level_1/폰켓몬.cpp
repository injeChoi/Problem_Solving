#include <bits/stdc++.h>
using namespace std;
#define MAX 200001

int arr[MAX];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solution(vector<int> nums) {
    int answer = 0, cnt = 0, capable = nums.size() / 2;
    for (int i = 0; i < nums.size(); i++) {
        arr[nums[i]]++;
    }
    for (int i = 0; i < MAX; i++) {
        if (arr[i] > 0) {
            cnt++;
        }
    }
    if (capable <= cnt) {
        answer = capable;
    }
    else {
        answer = cnt;
    }
    return answer;
}