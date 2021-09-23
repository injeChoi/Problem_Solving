def solution(n, computers):
    answer = 0
    parent = [0] * (n+1) 
    visited = [False] * (n+1)

    for i in range(n+1):
        parent[i] = i 
    
    def find_parent(x):
        if parent[x] != x:
            parent[x] = find_parent(parent[x])
        return parent[x]
    
    def union_parent(a, b):
        a = find_parent(a)
        b = find_parent(b)
        if a < b:
            parent[b] = a 
        else:
            parent[a] = b 
    
    for i in range(len(computers)):
        for j in range(len(computers)):
            if computers[i][j]:
                union_parent(i+1, j+1)

    # 집합 개수 카운트 
    for i in range(1, n+1):
        if visited[i]: 
            continue 
        visited[i] = True 
        answer += 1
        for j in range(i+1, n+1):
            # i와 연관된 모든 노드들은 한 잡합 안에 있다고 체크 
            if find_parent(i) == find_parent(j): 
                visited[j] = True

    return answer

solution(4, [[1, 1, 0, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 0, 1, 1]])