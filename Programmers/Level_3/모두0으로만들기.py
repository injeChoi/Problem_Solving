'''
https://programmers.co.kr/learn/courses/30/lessons/76503?language=python3#

Bottom-Up Traverse 개념이 중요

트리 구조 그래프에선 모든 노드가 root가 될 수 있긴 하지만 편의상 0번 정점을 root라고 하고
root 부터 순차적으로 모든 leaf 까지의 경로를 찾아본다

찾은 경로를 역순으로 돌면서, 부모는 자식의 가중치 만큼 증가시키면서 
bottom-up으로 root까지 연산을 하며 찾아갔을 떄 root가 0이 되면 성공
'''

from collections import deque

def solution(a, edges):
    answer = 0
    graph = [[] for _ in range(len(a))]
    
    for s, e in edges:
        graph[s].append(e)
        graph[e].append(s)
    
    def bfs():
        dq = deque([[-1, 0]])
        visited = [0] * len(a)
        visited[0] = 1
        paths = []

        while dq:
            s, e = dq.popleft()
            paths += [[s, e]]
            
            for child in graph[e]:
                if not visited[child]:
                    dq.append([e, child])
                    visited[child] = 1
        
        return paths[::-1][:-1]
    
    reversed_path = bfs()
    
    for parent, child in reversed_path:
        answer += abs(a[child])
        a[parent] += a[child]
        
    return answer if a[0] == 0 else -1

print(solution([-5,0,2,1,2], [[0,1],[3,4],[2,3],[0,3]]))