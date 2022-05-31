'''
https://www.acmicpc.net/problem/1987

시간 최적화에 모든게 달린 문제

어이없게도 범위 체크와 알파벳 방문 처리 검증하는 로직을 따로 함수화 하는 부분 때문에 시간 초과에 걸렸다

함수를 호출하는 과정에서의 오버헤드가 약간은 존재한다는 것은 알고 있었지만
이 부분이 시간초과를 야기하는 문제까지 될 줄을 상상도 못했다
'''

def solution():
    R, C = map(int, input().split())
    graph = [input() for _ in range(R)]
    occur = [False] * 26
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    answer = 0
 
    def dfs(y, x, cnt):
        nonlocal answer
        answer = max(answer, cnt)
        
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            
            if 0 <= ny < R and 0 <= nx < C and not occur[ord(graph[ny][nx]) - 65]:
                occur[ord(graph[ny][nx]) - 65] = True
                dfs(ny, nx, cnt + 1)
                occur[ord(graph[ny][nx]) - 65] = False
                
    occur[ord(graph[0][0]) - 65] = True
    dfs(0, 0, 1)
    print(answer)

solution()