#include <iostream>
#include <math.h>
using namespace std;

int T;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;
        long long N = a * pow(10, b);

        if (N == 10) {
            cout << "1-3-5-7-10" << endl;
        }

        else if (N <= 9) {
            if (N % 2 == 0) {
                for (int i = 2; i <= N;) {
                    cout << "-" << i;
                    i = i + 2;
                }
                cout << endl;
            }
            else {
                for (int i = 1; i <= N;) {
                    if (i == N) {
                        cout << i;
                        break;
                    }
                    else {
                        cout << i << "-";
                        i = i + 2;
                    }
                }
                cout << endl;
            }
        }
        else if (10 < N && N < 21) {
            if (N % 2 == 0) {
                cout << "-2-4-6";
                for (int i = 8; i <= N;) {
                    if (i == N) {
                        cout << "-" << i;
                        break;
                    }
                    else if (i > N) {
                        break;
                    }
                    else if (i < N){
                        cout << "-" << i;
                        i = i + 3;
                    }
                }
                cout << endl;
            }
            else {
                cout << "1-3-5";
                for (int i = 7; i <= N;) {
                    if (i == N) {
                        cout << "-" << i;
                        break;
                    }
                    else if (i > N) {
                        break;
                    }
                    else if (i < N) {
                        cout << "-" << i;
                        i = i + 3;
                    }
                }
                cout << endl;
            }
        }
        else {
            if (N % 2 == 0) {
                cout << "-2-4-6-";
                for (int i = 8; i <= 17;) {
                    if (i == 17) {
                        cout << i << "...";
                        break;
                    }
                    else {
                        cout << i << "-";
                        i = i + 3;
                    }
                }
                cout << endl;
            }
            else {
                cout << "1-3-5-";
                for (int i = 7; i <= 16;) {
                    if (i == 16) {
                        cout << i << "-...";
                        break;
                    }
                    else {
                        cout << i << "-";
                        i = i + 3;
                    }
                }
                cout << endl;
            }
        }

    }

    return 0;
}
