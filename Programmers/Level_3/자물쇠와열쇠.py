'''
https://programmers.co.kr/learn/courses/30/lessons/60059

자물쇠는 고정이고 키는 축소가(자물쇠의 범위를 벗어날 수 있다는 명세) 가능하다 
고로 자물쇠를 풀기위한 키의 모양을 먼저 구한다 
필요한 키의 모양(크기)을 파악했으면 그 범위대로 키를 부분 탐색해서 
홈과 돌기 모양이 자물쇠와 키가 반대인 부분이 존재하면 답을 True로 바꾼다

키는 시계방향으로 회전할 수도 있으므로 만약 현재 키의 모습에서 답을 찾지 못했다면
시계방향으로 돌려가면서 다시 범위 탐색을 진행한다 
'''

def solution(key, lock):
    answer = False
    y_pos = []
    x_pos = []
    N = len(lock)
    M = len(key)
    
    for i in range(N):
        for j in range(N):
            if lock[i][j] == 0:
                y_pos.append(i)
                x_pos.append(j)
    
    if not y_pos:
        return True
    
    y_pos.sort()
    x_pos.sort()
    y_min, x_min = y_pos[0], x_pos[0]
    y_max, x_max = y_pos[-1], x_pos[-1]
    target = [lock[i][x_min:x_max+1] for i in range(y_min, y_max+1)]
    y_len, x_len = len(target), len(target[0])
    
    def rotate():
        nonlocal key
        
        tmp = [[0] * M for _ in range(M)]
        for i in range(M):
            for j in range(M):
                tmp[i][j] = key[M-1-j][i]
                
        key = tmp
        
    def compare(tmp):
        for y in range(len(tmp)):
            for x in range(len(tmp[0])):
                if tmp[y][x] == target[y][x]:
                    return False
                
        return True
    
    def find_part():
        nonlocal answer 
        
        for i in range(M - y_len + 1):
            for j in range(M - x_len + 1):
                tmp = [key[k][j:j+x_len] for k in range(i, i+y_len)]
                
                if compare(tmp):
                    answer = True
                    return
                
    for _ in range(4):
        find_part()
        if answer: 
            break
        rotate()
    
    return answer

print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))