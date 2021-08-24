#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    // unique의 반환 값은 중복 값들이 뒤로 밀려서 저장되는 그 지점의 위치 
    // 고로, 그 부분 부터 벡터의 끝 까지 삭제하면 중복 값 들은 다 삭제 된다 
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> numbers = {2,1,3,4,1};
    vector<int> ans = solution(numbers);
    for (int i : ans) {
        cout << i << ' ';
    }
    return 0;
}