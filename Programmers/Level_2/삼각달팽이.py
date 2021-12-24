'''
https://programmers.co.kr/learn/courses/30/lessons/68645

순수 구현 문제
해당 라운드에 채워야할 배열의 길이를 나타내줄 s, e 포인터와 
둘 사이에서 적절하게 시작 포인트와 끝 포인트를 지정해줄 index하나를 조합하여 해결
'''

def solution(n):
    triangle = [[0] * x for x in range(1, n+1)]
    s, e = 0, n
    num, idx = 1, 0

    while s <= e:
        # 수직 채우기
        for i in range(s, e):
            triangle[i][idx] = num
            num += 1

        # 수평 채우기
        for i in range(idx + 1, e - idx):
            triangle[e-1][i] = num
            num += 1

        # 대각 위 채우기 
        s, e = s + 1, e - 1
        for i in range(e - 1, s - 1, -1):
            triangle[i][i-idx] = num
            num += 1

        idx += 1
        s += 1

    return sum(triangle, [])
