#include <bits/stdc++.h>
using namespace std;

int N, num, cnt, MIN;
vector<int> v, dist, vec;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GCD (int a, int b) {
  if (b == 0) 
    return a;
  else 
    return GCD(b, a % b);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = N-1; i > 0; i--) 
        dist.push_back(v[i] - v[i-1]);

    for (int i = 0; i < dist.size() - 1; i++) 
        vec.push_back(GCD(dist[i], dist[i+1]));
    
    sort(vec.begin(), vec.end());
    MIN = vec[0];

    int idx = 1;
    for (int i = v[0]+MIN; i < v.back(); i+=MIN) {
        if (i > v[idx]) idx++;
        if (idx == v.size()) break;
        if (i < v[idx]) cnt++;
    }
        
    cout << cnt << endl;
    return 0;
}