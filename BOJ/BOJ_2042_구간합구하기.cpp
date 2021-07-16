#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, K;
vector<ll> arr;
vector<ll> tree;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// 초기 전체 세그먼트 트리 만들기 
ll makeSegTree(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = makeSegTree(start, mid, node*2) + makeSegTree(mid+1, end, node*2+1);
}

// 특정 범위 내의 합 ==> 부분 합 구하기 
ll sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {    // leaf node일 경우 
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

// 특정 노드의 값 바꾸기 ==> 노드의 선조들 값도 다 바뀜 
void update(int start, int end, int node, int index, ll diff) {
    if (index < start || index > end) {
        return;
    }
    tree[node] += diff;

    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}

int main(int argc, char const *argv[]) {
    init();
    cin >> N >> M >> K;
    arr.resize(N);
    tree.resize(N*4);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    makeSegTree(0, N-1, 1); // arr의 시작은 0번 index, 끝은 N-1번, 세그먼트 트르의 index는 1로 시작하게 설정 

    for (int i = 0; i < M+K; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b; ll c;
            cin >> b >> c;
            ll gap = c - arr[b-1];  // 새로 바꿀 값이 원래 있던 값과 차이가 얼마나 나는지 계산해서 그 값 만큼 더해 줘야한다.
            arr[b-1] = c;           // 기존 배열에 새로운 값으로 최신화 
            update(0, N-1, 1, b-1, gap);// start, end, 몇번 노드 부터, 바꾸고 싶은 index, 값 차이
        }
        else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << sum(0, N-1, 1, b-1, c-1) << '\n';   // start, end, 몇번 노드부터, 구간1, 구간2 
        }
    }
    return 0;
}