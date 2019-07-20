#include <iostream>
#include <string>
int arr[26];
using namespace std;

int main() {
  int cnt=0, max=0, max_idx;
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 65 && str[i] <= 90)
    {
      arr[str[i] - 65]++;
    }
    else if (str[i] >= 97 && str[i] <= 122)
    {
      arr[str[i] - 97]++;
    }
  }

  for(int i=0; i<26; i++){  // arr에 담긴 내용 비교라 26번 돌려야 함
    if(max < arr[i]){
      max = arr[i];
      max_idx = i;
    }
  }

  for(int i=0; i<26; i++){
    if(max == arr[i]){
      cnt++;
      if(cnt >= 2){
        cout << "?" << endl;
        return 0;
      }
    }
  }
  cout << (char)(max_idx + 65) << endl;
  return 0;
}
