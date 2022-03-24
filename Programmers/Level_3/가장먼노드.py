'''
https://programmers.co.kr/learn/courses/30/lessons/49189

노드간 양방향 처리 
BFS로 가장 가까운 노드부터 depth를 줘가면서 탐색
방문한 노드는 visited 처리
'''

from collections import deque

def solution(n, edge):
    answer = 0
    graph = [[] for _ in range(n + 1)]
    visited = [0] * (n + 1)

    for path in edge:
        graph[path[0]].append(path[1])
        graph[path[1]].append(path[0])

    def bfs():
        visited[1] = 1
        q = deque()

        for item in graph[1]:
            q.append([item, 1])

        while q:
            node, depth = q.popleft()
            if not visited[node]:
                visited[node] = depth
                for vertex in graph[node]:
                    q.append([vertex, depth + 1])
    
    bfs()
    MAX = max(visited)
    answer = visited.count(MAX)

    return answer

print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))