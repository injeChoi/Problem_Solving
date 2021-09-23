# 최소 비용 신장 트리 비용 구하기 
 
v, e = map(int, input().split())
parent = [0] * (v+1)
edges = []
result = 0

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(x)
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a 
    else:
        parent[a] = b 

for i in range(1, v+1):
    parent[i] = i 

for _ in range(e):
    cost, a, b = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    # 사이클이 생기지 않을 때만 그래프 합치기 + 비용 추가 
    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        result += cost 

print(result)

