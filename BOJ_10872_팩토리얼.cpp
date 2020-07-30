#include <iostream>
#include <algorithm>
using namespace std;

int N;

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << factorial(N) << endl;

    return 0;
}
