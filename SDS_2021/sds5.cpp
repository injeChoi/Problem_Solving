#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int, int> > > jewerly(401);
vector<tuple<int, int, int> > black;
vector<tuple<int, int, int> > red;
vector<tuple<int, int, int> > blue;
vector<long long> result;
int N, K;
int x, y, color;
int total, idx;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) < get<2>(b);
}

long long getArea(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    pair<int, int> small, big;
    int smallX, smallY, bigX, bigY;
    long long area;

    smallX = min(p1.first, p2.first);
    smallX = min(smallX, p3.first);
    smallY = min(p1.second, p2.second);
    smallY = min(smallY, p3.second);
    small = make_pair(smallX, smallY);

    bigX = max(p1.first, p2.first);
    bigX = max(bigX, p3.first);
    bigY = max(p1.second, p2.second);
    bigY = max(bigY, p3.second);
    big = make_pair(bigX, bigY);

    area = abs(big.first - small.first) * abs(big.second - small.second);
    return area;
}

int main(int argc, char const *argv[]) {
    init(); 
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> N >> K;
            
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> color;
            if (color == 1) {
                black.push_back(make_tuple(x, y, color));
            }
            else if (color == 2) {
                red.push_back(make_tuple(x, y, color));
            }
            else {
                blue.push_back(make_tuple(x, y, color));
            }
        }

        sort(black.begin(), black.end(), compare);
        sort(red.begin(), red.end(), compare);
        sort(blue.begin(), blue.end(), compare);

        total = black.size() * red.size() * blue.size();

        for (int b = 0; b < black.size(); b++) {
            for (int r = 0; r < red.size(); r++) {
                for (int l = 0; l < blue.size(); l++) {
                    jewerly[idx].push_back(black[b]);
                    jewerly[idx].push_back(red[r]);
                    jewerly[idx].push_back(blue[l]);
                    idx++;
                }
            }
        }

        for (int i = 0; i < total; i++) {
            vector<pair<int, int> > p;
            for (int j = 0; j < jewerly[i].size(); j++) {
                p.push_back(make_pair(get<0>(jewerly[i][j]), get<1>(jewerly[i][j])));
            }
            if (result.empty()) {
                result.push_back(getArea(p[0], p[1], p[2]));
            }
            else {
                long long tmp = getArea(p[0], p[1], p[2]);
                if (tmp < result.back()) {
                    result.pop_back();
                    result.push_back(tmp);
                }
            }
        }
        sort(result.begin(), result.end());
        cout << "#" << testcase << " " << result[0] << endl;
        jewerly.clear();
        black.clear();
        red.clear();
        blue.clear();
        result.clear();
        N = 0; K = 0; x = 0; y = 0; color = 0; total = 0; idx = 0;
    }

    return 0;
}