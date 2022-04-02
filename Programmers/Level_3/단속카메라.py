'''
https://programmers.co.kr/learn/courses/30/lessons/42884?language=python3

진입, 탈출 구간의 범위를 따지다가 실패한 문제

카메라를 놓을 위치는 특정 구간의 탈출 지점만 고려하면 된다
Why? 
A의 진입, 탈출이 [-20, -10], B의 진입, 탈출이 [-14, 0]이라 할 때,
카메라를 A의 탈출 구간인 -10에 위치시키면 B의 구간 사이에 위치하게 되므로 
카메라를 추가로 구비할 필요가 없다

고로, 탈출 지점을 기점으로 배열을 정렬하여 
카메라 위치보다 B의 진입 지점이 크면 카메라를 추가해야 한다
반대로 카메라 위치보다 B의 진입 지점이 작거나 같으면 카메라를 추가할 필요가 없다
'''

def solution(routes):
    answer = 0
    point = -10**5
    routes.sort(key=lambda x: x[1])
    
    for enter, escape in routes:
        if point < enter:
            answer += 1
            point = escape
 
    return answer

print(solution([[0,1],[0,1],[1,2]]))