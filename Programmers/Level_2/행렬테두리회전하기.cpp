#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> table(101, vector<int>(101, 0));

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            table[i][j] = num++;
        }
    }

    for (int tc = 0; tc < queries.size(); tc++) {
        vector<int> v;
        int x1, x2, y1, y2;
        x1 = queries[tc][0]; y1 = queries[tc][1]; 
        x2 = queries[tc][2]; y2 = queries[tc][3];
        // 직사각형 정리 
        if (x1 > x2) {
            int tmp = 0;
            tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (y1 > y2) {
            int tmp = 0;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        // 최솟값 찾기 
        for (int i = x1; i <= x2; i++) {
            v.push_back(table[i][y1]);
            v.push_back(table[i][y2]);
        }
        for (int i = y1; i <= y2; i++) {
            v.push_back(table[x1][i]);
            v.push_back(table[x2][i]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[0]); // 찾은거 넣기 

        // 회전 시작 
        int idx = table[x1][y1];
        for (int i = x1; i < x2; i++) {
            table[i][y1] = table[i+1][y1];
        }
        for (int i = y1; i < y2; i++) {
            table[x2][i] = table[x2][i+1];
        }
        for (int i = x2; i > x1; i--) {
            table[i][y2] = table[i-1][y2];
        }
        for (int i = y2; i > y1+1; i--) {
            table[x1][i] = table[x1][i-1];
        }
        table[x1][y1+1] = idx;
    }
    return answer;
}
