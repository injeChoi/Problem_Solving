'''
https://www.acmicpc.net/problem/1967

공간 복잡도와 가장 먼 두 노드를 찾는 로직이 중요

두 노드 사이의 가중치를 저장하는 걸 2차원 배열로 처리했더니
1억 바이트 -> 대략 100메가, 여기에 인접리스트 + 다른 자잘한 메모리 요소들이 포함되니
메모리 초과 에러가 났다
고로 가중치 저장을 인접리스트 저장할 때 한 번에 처리하는 방식으로 수정

가장 먼 두 노드를 찾는 방식은 dfs 2번으로 처리 가능
1. 1번 노드에서 가장 먼 노드(s) 찾기 --- dfs 1번
2. s와 가장 먼 노드(e) 찾기        --- dfs 2번
3. s와 e 사이의 거리 출력
'''

def solution():
    N = int(input())
    graph = [[] for _ in range(N+1)]
    
    for _ in range(N-1):
        s, e, c = map(int, input().split())
        graph[s] += [[e, c]]
        graph[e] += [[s, c]]
        
        
    def find_most_far(idx):
        stack = [idx]
        while stack:
            node = stack.pop()
            for v, c in graph[node]:
                if distances[v] == -1:
                    distances[v] = distances[node] + c
                    stack += [v]


    distances = [-1] * (N+1)
    distances[1] = 0
    find_most_far(1)
    
    begin = distances.index(max(distances))
    
    distances = [-1] * (N+1)
    distances[begin] = 0
    find_most_far(begin)

    print(max(distances))
    
solution()