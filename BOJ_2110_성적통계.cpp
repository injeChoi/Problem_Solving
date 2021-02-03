#include <bits/stdc++.h>
using namespace std;

int K, N, num, MAX;
vector<int> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    freopen("input.txt", "r", stdin);
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> N;
        for (int k = 0; k < N; k++) {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < v.size()-1; j++) {
            if (v[j+1] - v[j] > MAX) 
                MAX = v[j+1] - v[j];
        }
        cout << "Class " << i+1 << endl;
        cout << "Max " << v[N-1] << ", " << "Min " << v[0] << ", " << "Largest gap " << MAX << endl;  
        v.clear();
        MAX = 0;
    }
    return 0;
}