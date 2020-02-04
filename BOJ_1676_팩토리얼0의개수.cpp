#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  int two = 0, five = 0;

  for (int i = 2; i <= N; i *= 2)
    two += N / i;

  for (int i = 5; i <= N; i *= 5)
    five += N / i;

  two < five ? cout << two << "\n" : cout << five << "\n";

  return 0;
}
