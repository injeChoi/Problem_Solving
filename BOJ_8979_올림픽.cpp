/*
 * 이 문제는 tuple로 풀 수 없었다. (내가 못푼걸지도)
 * 1. vector tuple로 풀어보려 했지만 tuple에는 나라 번호까지 담을 수 없었다.
 * 2. 벡터의 인덱스를 나라 번호로 사용할 수 있을까 싶었지만 어림도 없었다. 
 *    정렬하면 인덱스 때문에 나라 번호가 다 꼬인다. 
 */

#include<bits/stdc++.h>
using namespace std;

int N, K;
int country, gold, silver, bronze;
pair<pair<int ,int>, pair<int, int> > p[1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(pair<pair<int ,int>, pair<int, int> > i, pair<pair<int ,int>, pair<int, int> > j) {
    if (i.first.second > j.first.second) {
        return true;
    }
    else if (i.first.second == j.first.second) {
        if (i.second.first > j.second.first) {
            return true;
        }
        else if (i.second.first == j.second.first) {
            if (i.second.second > j.second.second) {
                return true;
            }
            else if (i.second.second == j.second.second) {
                return i.first.first == K;
            }
        }
    }
    return false;
}


int main(int argc, char const *argv[]) {
    init();
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first.first >> p[i].first.second >> p[i].second.first >> p[i].second.second;
    }
    
    sort(p, p + N, cmp);

    for (int i = 0; i < N; i++) {
        if (p[i].first.first == K) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}