#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9]; 
bool checkRow[9][10];       //[9]: 행 번호, [10]: 특정 행의 특정 열에 어떤 숫자가 있는지 체크
bool checkCol[9][10];
bool checkSquare[9][10];    //[9]: 3 * 3 네모칸 번호, [10]: 네모칸 안에 어떤 숫자가 있는지 체크 

int squareIdx(int y, int x) {
    return (y / 3) * 3 + x / 3;
}
// pos에 있는 empty_space를 어떤숫자로 채울지 판단 
void recu(int pos) {
    if (pos == 81) { // 다 채웠으면 출력하고 끝냄 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);    // 하나만 출력하고 종료 
    }
    // pos는 2차원 배열의 칸 하나하나를 의미하므로 pos 값에 따라 새로 좌표 설정 
    int y = pos / 9;
    int x = pos % 9;

    if (sudoku[y][x] != 0) {    // 채워져 있는 칸은 스킵 
        recu(pos+1);
    }
    else {                      // 빈 칸이면 
        for (int i = 1 ; i <= 9 ; i++) {    // 1~9까지 채워보기 
            int squareNum = squareIdx(y, x);// 현재 빈 칸이 몇 번 째 네모칸인지 계산 
            // i라는 숫자가 행, 열, 네모칸 안에서 쓰인 적이 없다면 
            if (!checkCol[x][i] && !checkRow[y][i] && !checkSquare[squareNum][i]) { 
                // i라는 숫자는 특정 행, 열, 네모에서 못 쓰게 막기 
                sudoku[y][x] = i;
                checkCol[x][i] = true;
                checkRow[y][i] = true;
                checkSquare[squareNum][i] = true;
                recu(pos+1);    // 다음 빈칸으로 이동 
                // 원 위치 (백 트래킹)
                sudoku[y][x] = 0;
                checkCol[x][i] = false;
                checkRow[y][i] = false;
                checkSquare[squareNum][i] = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                // 특정 행, 열, 네모칸에 어떤 숫자들이 쓰였는지 체크 
                checkCol[j][sudoku[i][j]] = true;
                checkRow[i][sudoku[i][j]] = true;
                checkSquare[squareIdx(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    recu(0);    // 0번째 칸 부터 백트래킹 시작 
}