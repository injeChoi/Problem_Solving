'''
https://programmers.co.kr/learn/courses/30/lessons/67259

DP가 추가돼야 마지막 테케 통과 가능

BFS로 순회하면서 조사하는데
큐 안에 들어가는 정보로 y, x, 진행방향, 소요비용이 들어간다
기본적인 BFS대로 진행하는데 추가되는 조건은 visited[ny][nx]에 들어있는 값이 
새로 추가될 값 보다 큰지도 체크하는 것 
'''

from collections import deque

def solution(board):
    N = len(board)
    visited = [[0] * N for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    
    def bfs():
        dq = deque()
        dq.append([0, 0, 0, 0])

        while dq:
            y, x, direction, cost = dq.popleft()
            
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                
                if 0 <= ny < N and 0 <= nx < N and not board[ny][nx]:
                    if ny == 0 and nx == 0:
                        continue
                    
                    if (y == 0 and x == 0) or direction == i:
                        next_cost = cost + 100
                        
                    else:
                        next_cost = cost + 600
                        
                    if visited[ny][nx] == 0 or next_cost <= visited[ny][nx]:
                        visited[ny][nx] = next_cost
                        dq.append([ny, nx, i, next_cost])
        
    bfs()
    return visited[N-1][N-1]


print(solution([[0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 1, 1, 1, 1, 1, 0], [1, 0, 0, 1, 0, 0, 0, 0], [1, 1, 0, 0, 0, 1, 1, 1], [1, 1, 1, 1, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 0], [1, 1, 1, 1, 1, 1, 1, 0], [1, 1, 1, 1, 1, 1, 1, 0]]))