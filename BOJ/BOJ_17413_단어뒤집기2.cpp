/*
'<'을 만나면 '>'을 만날 때 까진 공백 문자 신경쓰지 않고 차례대로 tmp에 저장하다가 한번에 출력 후 tmp 초기화
공백 문자를 만나면 tmp에 저장된 문자열 reverse 후 출력 및 초기화
마지막 문자를 만나면 tmp에 저장된 문자열 reverse 후 출력
일반 문자는 차례대로 tmp에 추가
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str; // 입력받은 문자열 저장
  getline(cin, str);  // 입력한 문자열 str로 전달

  string tmp; // str에 저장된 문자열을 한 글자씩 저장
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '<') {
      reverse(tmp.begin(), tmp.end());
      cout << tmp;
      tmp.clear();

      while(str[i] != '>') {
        tmp += str[i];
        i++;
      }
      tmp += str[i];
      cout << tmp;
      tmp.clear();
    }
    else if (str[i] == ' ') {
      reverse(tmp.begin(), tmp.end());
      cout << tmp << " ";
      tmp.clear();
    }
    else if (i == str.length() - 1) {
      tmp += str[i];
      reverse(tmp.begin(), tmp.end());
      cout << tmp;
    }
    else
      tmp += str[i];
  }
  cout << '\n';

  return 0;
}
