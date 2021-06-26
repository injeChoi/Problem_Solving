#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
char arr1[101][101];
char arr2[101][101];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c;
      arr1[i][j] = c;
    }
  }

  int tmp = M - 1;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (arr1[j][tmp] == '-')
        arr2[i][j] = '|';
      else if (arr1[j][tmp] == '|')
        arr2[i][j] = '-';
      else if (arr1[j][tmp] == '/')
        arr2[i][j] = 92;
      else if (arr1[j][tmp] == 92)
        arr2[i][j] = '/';
      else if (arr1[j][tmp] == '^')
        arr2[i][j] = '<';
      else if (arr1[j][tmp] == '<')
        arr2[i][j] = 'v';
      else if (arr1[j][tmp] == 'v')
        arr2[i][j] = '>';
      else if (arr1[j][tmp] == '>')
        arr2[i][j] = '^';
      else
        arr2[i][j] = arr1[j][tmp];
    }
    tmp--;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr2[i][j];
    }
    cout << endl;
  }

  return 0;
}
