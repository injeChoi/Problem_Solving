/* 투 포인터에 대해 알 수 있다 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

int N;
long long int arr[MAX];
long long int resA, resB;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//양쪽에서 다가오는 index의 초기값
	int left = 0;
	int right = N - 1;

	//결과값의 초기값
	int resLiquid = abs(arr[left] + arr[right]);
	resA = arr[left];
	resB = arr[right];

	//양쪽에서 다가오는 반복, 모든 경우 탐색 완료시 종료
	while (left < right) {
		int tmpLiquid = arr[left] + arr[right];
		if (abs(tmpLiquid) < resLiquid) {
			resLiquid = abs(tmpLiquid);
			resA = arr[left];
			resB = arr[right];
		}

		if (tmpLiquid < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << resA << " " << resB << "\n";
  return 0;
}
