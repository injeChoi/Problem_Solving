#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int> > v;
int s, t;
priority_queue<int, vector<int>, greater<int> > pq;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {
        if (pq.top() > v[i].first) 
            pq.push(v[i].second);
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << endl;
    return 0;
}