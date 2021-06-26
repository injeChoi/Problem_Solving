#include <iostream>
#include <algorithm>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    string s; cin >> s;
    int arr[10] = {0};
    int cnt = 0;
 
    for(int i = 0; i < s.size(); i++)   // 숫자 별로 몇 개 나왔는지 체크 
        arr[s[i] - '0']++;
 
    for(int i = 0; i < 10; i++)         // 6, 9가 아닌 숫자들 중에 가장 많이 나온거 찾기 
        if(i != 9 && i != 6)            // 그것들은 나온 수대로 1 세트 추가니까 
            cnt = max(cnt, arr[i]);     // 6, 9는 각각 두 번 또는 6, 9가 따로 한 번씩 나오는게 1세트니까 
                                        // 합해서 짝수이게 만들어서 2로 나눈 값이 6과 9의 세트 수 
    cout << max(cnt, (arr[6] + arr[9] + 1) / 2) << endl;    // 6,9 세트가 많은지 다른 숫자가 많은지 체크
    return 0;
}
