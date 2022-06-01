'''
https://www.acmicpc.net/problem/1707

무방향 인접리스트 생성 후
dfs 방식으로 현재 노드와 연결된 다음 노드를 방문처리한다
이때, 현재 노드와 다음 노드를 다른 색으로 칠해가는 로직을 사용한다
연결돼있는 서로 다른 모든 노드가 다른 색으로 칠해져있다면 이는 이분 그래프를 의미하기 때문이다

고로 만약 인접한 노드가 같은 색으로 칠해진다면 이는 이분 그래프가 아님을 의미하므로 NO를 출력하는 로직을 만든다

답은 동일하지만,
DFS를 사용할 때 재귀를 쓰면 메모리 초과(pypy3), 시간 초과(python3)가 난다
recursion limit을 2만으로 제한하더라도 메모리 초과가 발생하는데 이유를 알 수 없다...
고로 스택을 이용해 DFS 처리를 한다 
'''

T = int(input())

def solution():
    V, E = map(int, input().split())
    graph = [[] for _ in range(V + 1)]
    visited = [0] * (V + 1)
    
    for _ in range(E):
        s, e = map(int, input().split())
        graph[s] += [e]
        graph[e] += [s]
        
    def dfs(idx):
        st = [idx]
        visited[idx] = 1
        
        while st:
            node = st.pop()
            
            for i in graph[node]:
                if visited[i] == visited[node]:
                    return False
                elif not visited[i]:
                    visited[i] = -visited[node]
                    st += [i]
                    
        return True
        
    
    for i in range(1, V+1):
        if not visited[i]:
            bipartie = dfs(i)
            if not bipartie:
                break
    
    if not bipartie:
        print("NO")
    else:
        print("YES")

for i in range(T):
    solution()