#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[26] = {0};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
    arr[str[i] - 'a'] += 1;

  for (int i = 0; i < 26; i++) {
    if (i == 25)
      cout << arr[i];
    else
      cout << arr[i] << " ";
  }
  return 0;
}
