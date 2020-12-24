#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(int argc, char const *argv[]) {
    init();
    int W, H; cin >> W >> H;
    vector<pair<int, int> > location;
    int num; cin >> num;
    int x = 0, y = 0;
    int total = 0;
    
    for (int i = 0; i < num; i++) {
        int direction, distance; 
        cin >> direction >> distance;
        location.push_back(make_pair(direction, distance));
    }
    cin >> x >> y;

    for (int i = 0; i < location.size(); i++) {
        if (x < 3) { // 동근이 시작 위치가 북, 남  
            if (location[i].first < 3 && location[i].first != x)  // 맞은편
                total += min(H + y + location[i].second, H + (W - y) + (W - location[i].second));
            
            else if (location[i].first < 3 && location[i].first == x)  // 같은곳
                total += abs(location[i].second - y);
            
            if (x == 1) { //북쪽 일 때
                if (location[i].first == 4)  // 동쪽
                    total += W - y + location[i].second;
                
                else if (location[i].first == 3)  // 서쪽
                    total += y + location[i].second;
            }
            else if (x == 2) { //남쪽 일 때 
                if (location[i].first == 4)  // 동쪽
                    total += W - y +  H - location[i].second;
                
                else if (location[i].first == 3)  // 서쪽
                    total += y + H - location[i].second;
            }
        }
        else {  // 동근이 위치가 동, 서
            if (location[i].first > 2 && location[i].first != x)  // 맞은편
                total += min(W + y + location[i].second, W + (H - y) + (H - location[i].second));
            
            else if (location[i].first > 2 && location[i].first == x)  // 같은곳
                total += abs(location[i].second - y);
            
            if (x == 3) { // 서쪽일 때
                if (location[i].first == 1)  // 북
                    total += y + location[i].second;
                
                else if (location[i].first == 2)  // 남
                    total += (H - y) + location[i].second;
            }
            else if (x == 4) { // 동쪽일 때 
                if (location[i].first == 1)  // 북
                    total += y +  W - location[i].second;
                
                else if (location[i].first == 2)  // 남
                    total += H - y + W - location[i].second;
            }
        }
    }

    cout << total;
    return 0;
}