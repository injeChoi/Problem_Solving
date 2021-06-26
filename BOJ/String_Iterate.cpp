#include <iostream>
#include <string>
using namespace std;

int main(){
  int testcase=0;
  cin >> testcase;

  for(int i=0; i<testcase; i++){
    int iterate =0;
    string str;
    cin >> iterate >> str;

    for(int j=0; j<str.length(); j++){
      for(int k=0; k<iterate; k++){
        cout << str[j];
      }
    }
    cout << endl;
  }
}
