#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// 키패드 위치 좌표 
pii keypad[10] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
// 위치랑 누를 번호를 인자로 받아서 상대 거리 리턴
int Euclidean_Distance(pii hand, int num) {
    return abs(hand.first - keypad[num].first) + abs(hand.second - keypad[num].second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pii finger[2] = {{3,0}, {3,2}};  // 손가락 시작 위치 좌표 

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) { // 왼쪽 column은 왼쪽 손가락 
            finger[0] = keypad[numbers[i]];
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) { // 오른쪽 column은 오른쪽 손가락 
            finger[1] = keypad[numbers[i]];
            answer += "R";
        }
        else {                                                          // 중간 column은 거리 짧은 손가락 
            int leftDistance = Euclidean_Distance(finger[0], numbers[i]);
            int rightDistance = Euclidean_Distance(finger[1], numbers[i]);

            if (leftDistance == rightDistance) {    // 거리가 같으면 무슨 손잡이인지 판단 후 그 손가락으로 
                if (hand == "left") {
                    finger[0] = keypad[numbers[i]];
                    answer += "L";
                }
                else if (hand == "right") {
                    finger[1] = keypad[numbers[i]];
                    answer += "R";
                }
            }
            else if (leftDistance < rightDistance) {
                finger[0] = keypad[numbers[i]];
                answer += "L";
            }
            else if (rightDistance < leftDistance){
                finger[1] = keypad[numbers[i]];
                answer += "R";
            }
        }
    }
    return answer;
}
