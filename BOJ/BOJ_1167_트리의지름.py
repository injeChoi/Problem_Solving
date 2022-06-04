'''
https://www.acmicpc.net/problem/1167

입력 파싱에만 신경 쓰면 https://www.acmicpc.net/problem/1967 이 문제와 같은 문제
'''

def solution():
    N = int(input())
    graph = [[] for _ in range(N+1)]
    
    for _ in range(N):
        lst = list(map(int, input().split()))
        s = lst[0]
        for i in range(1, len(lst), 2):
            if lst[i] == -1:
                break
            e, c = lst[i], lst[i+1]
            graph[s] += [[e, c]]
            
    
    def dfs(idx):
        stack = [idx]
        while stack:
            node = stack.pop()
            for v, c in graph[node]:
                if distances[v] == -1:
                    distances[v] = distances[node] + c
                    stack += [v]
        
    
    distances = [-1] * (N+1)
    distances[1] = 0
    dfs(1)
    
    begin = distances.index(max(distances))
    
    distances = [-1] * (N+1)
    distances[begin] = 0
    dfs(begin)
    
    print(max(distances))

solution()