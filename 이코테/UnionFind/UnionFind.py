# 특정 원소가 속한 집합 찾기 = 루트 찾기 
def find_parent(x):
    # 내가 루트가 아니라면 
    if parent[x] != x:
        # 루트를 찾아가보자, 경로 압축 (특정 원소가 거쳐간 노드의 부모 테이블은 다 루트 번호가 기록됨)
        parent[x] = find_parent(parent[x])
    return parent[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b 

# 노드와 간선 개수 입력받기 
v, e = map(int, input().split())
# 부모 테이블 초기화 
parent = [0] * (v+1)
# 사이클 판별 
cycle  = False
# 부모 테이블에 처음엔 자기 자신이 부모로 초기화
for i in range(1, v+1):
    parent[i] = i

# 간선 별로 Union 연산 수행
for _ in range(e):
    a, b = map(int, input().split())
    # 사이클이 발생했으면 종료 
    if find_parent(a) == find_parent(b):
        cycle = True 
        break
    else:
        union_parent(a, b)

if cycle:
    print("사이클이 발생했습니다.")
else:
    print("사이클이 발생하지 않았습니다.")

# 각 원소가 속한 집합 출력
for i in range(1, v+1):
    print(find_parent(i), end=" ")
print()

# 부모 테이블 출력
for i in range(1, v+1):
    print(parent[i], end=" ")
print()