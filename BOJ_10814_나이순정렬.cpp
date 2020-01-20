#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct {
  int age;
  string name;
  int seq = 0;
}info;

bool comp(const info &A, const info &B) {
  if(A.age == B.age)
    return A.seq < B.seq;

  else
    return A.age < B.age;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  info data;
  vector<info> v;

  for (int i = 0; i < N; i++) {
    cin >> data.age >> data.name;
    v.push_back({data.age, data.name, data.seq++});
  }

  sort(v.begin(), v.end(), comp);

  for (int i = 0; i < N; i++) {
    cout << v[i].age << " " << v[i].name << "\n";
  }

  return 0;
}
