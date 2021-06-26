/*
https://www.acmicpc.net/problem/1662
bottom-up으로, 재귀적으로 푸는게 관건.
bracket 배열에 특정 괄호의 끝점을 표기해두면
재귀 함수에서 괄호가 시작되는 부분이 발견될 때 
그 괄호의 끝은 어딘지 알려줄 수 있게된다. 
*/
#include <iostream> 
#include <string> 
#include <stack> 
using namespace std; 

int bracket[50]; 
string str;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int recursive(int start, int end) { 
    int result = 0; 
    int round = 0;
    for (int i = start; i < end; i++) { 
        if (str[i] == '(') { 
            round = str[i - 1] - '0'; //정수로 만들기 
            result += round * recursive(i + 1, bracket[i]) - 1; //result가 ')' 개수 까지 세므로 -1
            i = bracket[i]; //')' 뒤로 이동 
            continue; 
        } 
        result++; 
    } 
    return result; 
} 

int main(void) { 
    init();
    stack<int> s;
    cin >> str; 
    
    for (int i = 0; i < str.length(); i++) { 
        if (str[i] == '(') // '(' 시작점 표기 
            s.push(i); 
        
        else if (str[i] == ')') {  // '('과 쌍이 되는 ')' 지점 표기 
            bracket[s.top()] = i; 
            s.pop(); 
        } 
    } 
    cout << recursive(0, str.length()) << endl; 
    return 0; 
}
