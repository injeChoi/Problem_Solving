'''
https://programmers.co.kr/learn/courses/30/lessons/87391?language=python3

완전탐색 시간초과 실패 코드
다른 사람 풀이 이해 불가

이동방향
0: 좌, 1: 우, 2: 상, 3: 하
'''

def solution(n, m, x, y, queries):
    answer = 0
    
    def simulating(dy, dx):
        for direction, length in queries:
            if direction == 0:
                dx = 0 if dx - length < 0 else dx - length
            elif direction == 1:
                dx = m - 1 if dx + length >= m else dx + length
            elif direction == 2:
                dy = 0 if dy - length < 0 else dy - length
            else:
                dy = n - 1 if dy + length >= n else dy + length
            
        return dy, dx
    
    for ny in range(n):
        for nx in range(m):
            dy, dx = simulating(ny, nx)
            if dy == x and dx == y:
                answer += 1
    
    return answer

print(solution(2,5,0,1,[[3,1],[2,2],[1,1],[2,3],[0,1],[2,1]]))
