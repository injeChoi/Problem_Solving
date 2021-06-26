#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

// 최소 연쇄 행렬 곱 함수
#include <iostream>
using namespace std;
int main(){
	int N;
	int input[2][501];
	int output[501][501];

    // 입력
    cin >> N;
	for (int i = 1; i <= N; i++){
		// 행렬 첫번째 원소
        cin >> input[0][i];
        // 행렬 두번째 원소
		cin >> input[1][i];
		output[i][i] = 0;
	}

    // 계산
	for (int diagonal = 1; diagonal <= N - 1; diagonal++){
		for (int i = 1; i <= N - diagonal; i++){
			int j = i + diagonal;

            // 최소값 구하기
            int min = 987654321;
			int temp;
            for (int k = i; k < j; k++){
				temp = output[i][k] + output[k + 1][j] + (input[0][i] * input[0][k+1] * input[1][j]);
				if (temp < min)
					min = temp;
			}
	 		output[i][j] = min;
		}
	}

    // 출력
	cout << output[1][N] << endl;
}
