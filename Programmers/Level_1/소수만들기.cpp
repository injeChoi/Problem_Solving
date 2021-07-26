#include <bits/stdc++.h>
using namespace std;
#define MAX 3001

bool isPrime[MAX];
int makeSum[3];
int answer;

void sosu() {
    for (int i = 2; i < MAX; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < sqrt(MAX); i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

void DFS(vector<int> &tmpNums, int idx, int cnt) {
    // 종료조건 
    if (cnt == 3) {
        if (isPrime[makeSum[0] + makeSum[1] + makeSum[2]]) {
            answer++;
        }
        return;
    }
    for (int i = idx; i < tmpNums.size(); i++) {
        makeSum[cnt] = tmpNums[i];
        DFS(tmpNums, i+1, cnt+1);
    }
}

int solution(vector<int> &nums) {
    sosu();
    DFS(nums, 0, 0);
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> nums = {1,2,3,4};
    cout << solution(nums) << endl;
    return 0;
}