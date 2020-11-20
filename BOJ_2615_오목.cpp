// #include <iostream>
// #include <algorithm>
// using namespace std;

// int board[19][19];

// void init() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// }

// int rowConnect(int cnt, int row, int col, int color) {
//     for (int i = 1; i < 19 - col; i++) {
//         if (board[row][col+i] == color && cnt < 5)
//             cnt++;
//         else {
//             if (cnt == 5 && col+i < 18 && board[row][col+i+1] != color) 
//                 return cnt;
//             else if (cnt == 5 && col+i == 18)
//                 return cnt;
//             else {
//                 cnt = 1;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// int colConnect(int cnt, int row, int col, int color) {
//     for (int i = 1; i < 19 - row; i++) {
//         if (board[row+i][col] == color && cnt < 5)
//             cnt++;
//         else {
//             if (cnt == 5 && row+i < 18 && board[row+i+1][col] != color) 
//                 return cnt;
//             else if (cnt == 5 && row+i == 18)
//                 return cnt;
//             else {
//                 cnt = 1;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// void checkRow() {
//     int cnt = 1, color;
//     bool exit = false;
//     for (int row = 0; row < 19; row++) {
//         for (int col = 0; col < 15; col++) {
//             if (board[row][col] != 0) 
//                 color = board[row][col];
//             if (color != 0) {
//                 if (board[row][col] == color) 
//                     cnt = rowConnect(cnt, row, col, color);
//                 if (cnt == 5) {
//                     exit = true;
//                     cout << color << endl;
//                     cout << row + 1 << " " << col + 1 << endl;
//                     break;
//                 }   
//             }
//         }
//         if (exit) break;
//     }
// }

// void checkCol() {
//     int cnt = 1, color;
//     bool exit = false;
//     for (int col = 0; col < 19; col++) {
//         for (int row = 0; row < 15; row++) {
//             if (board[row][col] != 0) 
//                 color = board[row][col];
//             if (color != 0){
//                 if (board[row][col] == color) 
//                     cnt = colConnect(cnt, row, col, color);
//                 if (cnt == 5) {
//                     exit = true;
//                     cout << color << endl;
//                     cout << row + 1 << " " << col + 1 << endl;
//                     break;
//                 }
//             }
//         }
//         if (exit) break;
//     }
// }

// int toRight(int cnt, int row, int col, int color) {
//     for (int i = 1; i < 19 - row; i++) {
//         if (board[row+i][col+i] == color && cnt < 5)
//             cnt++;
//         else {
//             if (cnt == 5 && row+i < 18 && board[row+i+1][col+i+1] != color) 
//                 return cnt;
//             else if (cnt == 5 && row+i == 18)
//                 return cnt;
//             else {
//                 cnt = 1;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// int toLeft(int cnt, int row, int col, int color) {
//     for (int i = 1; i < 19 - row; i++) {
//         if (board[row+i][col-i] == color && cnt < 5)
//             cnt++;
//         else {
//             if (cnt == 5 && row+i < 18 && board[row+i+1][col-i-1] != color) 
//                 return cnt;
//             else if (cnt == 5 && row+i == 18)
//                 return cnt;
//             else {
//                 cnt = 1;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }


// void checkDiagonal() {
//     int cnt = 1, color;
//     bool exit = false;
//     for (int row = 0; row < 15; row++) {
//         for (int col = row; col < 19; col++) {
//             if (board[row][col] != 0) 
//                 color = board[row][col];

//             if (color != 0) {
//                 if (board[row][col] == color && 3 < col && col < 15) { // 양 방향 가능
//                     cnt = toRight(cnt, row, col, color);
//                     if(cnt != 5) 
//                         cnt = toLeft(cnt, row, col, color);
//                 }
//                 else if (board[row][col] == color && col < 4) 
//                     cnt = toRight(cnt, row, col, color);

//                 else if (board[row][col] == color && col > 14) 
//                     cnt = toLeft(cnt, row, col, color);

//                 if (cnt == 5) {
//                     exit = true;
//                     cout << color << endl;
//                     cout << row + 1 << " " << col + 1 << endl;
//                     break;
//                 }   
//             }
//         }
//         if (exit) break;
//     }
// }

// int main(int argc, char const *argv[]) {
//     init();
//     freopen("input.txt", "r", stdin);
//     int input;
//     for (int row = 0; row < 19; row++)
//         for (int col = 0; col < 19; col++) {
//             cin >> input;
//             board[row][col] = input;
//         }

//     checkRow();
//     checkCol();
//     checkDiagonal();

//     return 0;
// }

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 20
#define RIGHT 1
#define DOWN 2
#define RIGHTDOWN 3
#define LEFTDOWN 4
using namespace std;
 
int arr[N][N]; //전체맵
 
//입력받음
void input(){
    for(int y=1; y<N; y++){
        for(int x=1; x<N; x++){
            scanf("%d", &arr[y][x]);
        }
    }
}
 
//y,x 가 맵 내부에 있는지 검사
bool isInside(int y, int x){
    return (y>=1 && y<N) && (x>=1 && x<N);
}
 
//가장 왼쪽에 있는 점을 출력하기 위한 정렬 기준
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
 
//누군가 이긴경우 출력
void myPrint(int color, pair<int, int> p){
    cout << color << endl;
    cout << p.first <<" " << p.second;
}
//비긴경우 출력
void myPrintFail(){
    cout <<"0";
}
//처음 검사한건지 = 돌이 가운데 있는것인지 확인
bool isMiddle(int y, int x, int color, int direction){
    if(direction == RIGHT && isInside(y, x-1)){
        if(arr[y][x-1]==color) return false;
    }
    if(direction == DOWN && isInside(y-1, x)){
        if(arr[y-1][x]==color) return false;
    }
    if(direction == RIGHTDOWN && isInside(y-1, x-1)){
        if(arr[y-1][x-1]==color) return false;
    }
    if(direction == LEFTDOWN && isInside(y-1, x+1)){
        if(arr[y-1][x+1]==color) return false;
    }
 
    return true;
}
 
//색이 같은 돌이 한 방향으로 이어져있는가
bool omok(int y, int x, int color, int direction) {
    if(!isMiddle(y, x, color, direction)) return false;
 
    vector<pair<int, int> > v;
    v.push_back(pair<int, int>(y, x));
    int dx = x;
    int dy = y;
 
    if(direction == RIGHT){
        while(arr[dy][++dx] == color){
            v.push_back(pair<int, int>(dy, dx));
        }
    }else if(direction == DOWN){
        while(arr[++dy][dx] == color){
            v.push_back(pair<int, int>(dy, dx));
        }
    }else if(direction == RIGHTDOWN){
        while(arr[++dy][++dx] == color){
            v.push_back(pair<int, int>(dy, dx));
        }
    }else if(direction == LEFTDOWN){
        while(arr[++dy][--dx] == color){
            v.push_back(pair<int, int>(dy, dx));
 
        }
    }
 
    if(v.size() == 5){
        sort(v.begin(), v.end(), compare);
        myPrint(color, v[0]);
        return true;
    }
    return false;
}
 
//가로로 검사하면서 돌이 있으면 solution 호출
bool solution(){
    for(int y=1; y<N; y++){
        for(int x=1; x<N; x++){
            int color = arr[y][x];
            if(color!=0){
                if(color == arr[y][x+1]){
                    if(omok(y, x, color, RIGHT)) return true;
                }
                if(color == arr[y+1][x]) {
                    if(omok(y, x, color, DOWN)) return true;
                }
                if(color == arr[y+1][x+1]) {
                    if(omok(y, x, color, RIGHTDOWN)) return true;
                }
                if(color == arr[y+1][x-1]){
                    if(omok(y, x, color, LEFTDOWN)) return true;
                }
            }
        }
    }
    return false;
}
 
int main(void){
    input();
    if(!solution()) myPrintFail();
    return 0;
}