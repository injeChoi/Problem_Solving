#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(int argc, char const *argv[]) {

    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int N = 0, K = 0, idx = 0;
        string str = "";
        cin >> N >> K;

        vector<int> count, total;
        //deque<deque<int> > r(N, deque<int>(K, 0));
        deque<deque<pair<int, int> > > ring(N, deque<pair<int, int> >(K, make_pair(0, 0)));
        deque<deque<pair<int, int> > > dq;
        //deque<int> d(K, 0);
        deque<pair<int, int> > d(K, make_pair(0, 0));


        for (int i = 0; i < K; i++) {
            cin >> str;
            pair<int, int> p;
            for (int j = 0; j < str.length(); j++) {
                int tmp = str[j] - '0';
                p = make_pair(tmp, i);
                ring[j][i] = p;
            }
        }

        for (int i = 0; i < N; i++) {
            d = ring[i];
            for (int k = 0; k < d.size()-1; k++) {
                ring[i].push_back(d[k]);
            }
            for (int j = d.size()-1; j > 0; j--) {
                ring[i].push_front(d[j]);
            }
        }

        dq.resize(ring.size());
        copy(ring.begin(), ring.end(), dq.begin());

        for (int idx = d.size() - 1; idx < d.size() - 1 + K; idx++) {
            int sum = 0;

            for (int i = 0; i < N; i++) {
                int left = 0, right = 0;
                deque<pair<int, int>>::iterator low, up;
                if (dq[i][idx].first == 1) {
                    count.push_back(0);
                }
                else {
                    sort(dq[i].begin(), dq[i].begin()+idx);
                    for (int w = 0; w < K; w++) {
                        for (int j = 0; j < dq[w].size(); j++) {
                            cout << dq[w][j].first << "," << dq[w][j].second << " ";
                        }
                        cout << endl;
                    }
                    up = upper_bound(dq[i].begin(), dq[i].begin()+idx-1, make_pair(1, 0), comp);
                    left = up - dq[i].begin();

                    sort(dq[i].begin()+idx+1, dq[i].end());
                    for (int w = 0; w < K; w++) {
                        for (int j = 0; j < dq[w].size(); j++) {
                            cout << dq[w][j].first << "," << dq[w][j].second << " ";
                        }
                        cout << endl;
                    }
                    low = lower_bound(dq[i].begin()+idx+1, dq[i].end(), make_pair(1, 0), comp);
                    right = low - dq[i].begin()+idx+1;
                    
                    cout << left << " " << right << endl;
                    count.push_back(min(left, right));
                }
            }
            for (int i = 0; i < count.size(); i++) {
                sum += count[i];
            }
            total.push_back(sum);
            count.clear();
        }


        // for (int i = 0; i < K; i++) {
        //     for (int j = 0; j < ring[i].size(); j++) {
        //         cout << ring[i][j].first << "," << ring[i][j].second << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < K; i++) {
        //     for (int j = 0; j < N; j++) {
        //         scanf("%1d", &r[j][i]);                
        //     }
        // }

        // for (int i = 0; i < N; i++) {
        //     d = r[i];
        //     for (int k = 0; k < d.size()-1; k++) {
        //         r[i].push_back(d[k]);
        //     }

        //     for (int j = d.size()-1; j > 0; j--) {
        //         r[i].push_front(d[j]);
        //     }
        // }

        // for (int idx = d.size() - 1; idx < d.size() - 1 + K; idx++) {
        //     int sum = 0;

        //     for (int i = 0; i < N; i++) {
        //         int left = 0, right = 0;

        //         if (r[i][idx] == 1) {
        //             count.push_back(0);
        //         }
        //         else {
        //             for (int j = idx; j >= 0; j--) {
        //                 if (r[i][j] == 1) {
        //                     break;
        //                 }
        //                 left++;
        //             }
        //             for (int k = idx; k < r[i].size(); k++) {
        //                 if (r[i][k] == 1) {
        //                     break;
        //                 }
        //                 right++;
        //             }
        //             count.push_back(min(left, right));
        //         }
        //     }
        //     for (int i = 0; i < count.size(); i++) {
        //         sum += count[i];
        //     }
        //     total.push_back(sum);
        //     count.clear();
        // }

        // sort(total.begin(), total.end());
        // cout << "#" << testcase << " " << total.front() << endl;
    }

    return 0;
}