'''
https://programmers.co.kr/learn/courses/30/lessons/68936

재귀적으로 분할 정복하는 것이 핵심
영역 안에 값이 통일돼있지 않다면 영역을 4분할 시작
재귀 함수의 매개변수로 특정 영역의 y, x값과 범위를 넘겨줌 
특정 영역 안에서 값이 통일 돼있는지 다시 체크 
통일 돼있다면 통일 된 값을 answer에 추가 
'''

def solution(arr):
    answer = [0, 0]
    N = len(arr)

    def comp(y, x, n):
        # 영역안에 값들이 같은 값인지 확인할 때 기준이 되는 값
        value = arr[y][x]

        for i in range(y, y + n):
            for j in range(x, x + n):
                # 기준 값과 다른 값 발견하면 분할 시작 
                if value != arr[i][j]:
                    half = n // 2
                    # 좌상단
                    comp(y, x, half)
                    # 좌하단
                    comp(y + half, x, half)
                    # 우상단
                    comp(y, x + half, half)
                    # 우하단 
                    comp(y + half, x + half, half)
                    # 원래 영역은 압축 불가 영역이므로 answer에 값 추가하지 않고 종료 
                    return
        
        # 특정 영역에서 모든 값이 동일하면 해당 값의 개수 +1 
        answer[value] += 1

    # 원형 정사각형 (초기 값)도 하나의 S라고 볼 수 있기 때문에 전체 영역부터 탐색 
    comp(0, 0, N)
    return answer
