// Segment Tree + Relabeling(좌표압축)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii player[500000];
int N, num;
int tree[1<<20];

int seg_sum(int node, int s, int e, int l, int r) {
    if (r < s || e < l) {   // 범위 체크 
        return 0;
    }
    if (l <= s && e <= r) {
        return tree[node];
    }
    else {  // 자식한테 찾으라고 하기 
        return seg_sum(node*2, s, (s+e)/2 , l ,r) + seg_sum(node*2+1, (s+e)/2+1, e, l, r);
    }
}

void update(int node, int s, int e, int idx, int v) {
    if (idx < s || e < idx) {
        return;
    }
    if (s == e) {
        tree[node] = v;
    }
    else {
        update(node*2, s, (s+e)/2, idx, v);
        update(node*2+1, (s+e)/2+1, e, idx,v);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

bool compare(pii a, pii b) {
    return a.second < b.second;
}

int main(int argc, char const *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int power; scanf("%d", &power);
        player[i].first = i;
        player[i].second = power;
    }
    // 평소 실력 순으로 정렬 
    sort(player, player + N, compare);

    // Relabeling(좌표압축)
    for (int i = 0; i < N; i++) {
        player[i].second = ++num;
    }
    // 다시 원래 순서대로 정렬 
    sort(player, player + N);

    for (int i = 0; i < N; i++) {
        int curPower = player[i].second;
        int cnt = 0;
        if (curPower > 1) {
            cnt = seg_sum(1, 1, num, 1, curPower-1);
        }
        update(1, 1, num, curPower, 1);
        printf("%d\n", i + 1- cnt);
    }
    return 0;
}