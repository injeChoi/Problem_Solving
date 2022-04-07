'''
https://programmers.co.kr/learn/courses/30/lessons/42861?language=python3

최단경로를 구하는데 특정 정점에서의 최소비용이 아니라 그래프의 최소비용이니까 최소신장트리 
=> 크루스칼 or 프림  

크루스칼 코드 로직: Union Find + 사이클 판별 

각 원소마다 부모를 알려주는 부모 배열 선언 (처음엔 자기자신이 부모)
부모 찾기 로직 (경로압축 필수), 부모 합치기 로직 (부모를 비교해서 더 상위인 그룹한테 합침)

사이클 판별을 위해 각 경로를 조사하면서
출발 정점과 도착 정점의 부모를 비교해서 다른 부모를 가지고 있으면
서로 연결되도 사이클이 안 생기는 놈들이니 합치기 실행 (Union)
합치면 그 간선의 가중치를 총 비용에 추가 
'''

def solution(n, costs):
    answer = 0
    parent = [x for x in range(n + 1)]
    costs.sort(key = lambda x: x[2])

    def findParent(x):
        if parent[x] != x:
            parent[x] = findParent(parent[x])
        return parent[x]
    
    def unionParent(a, b):
        a = findParent(a)
        b = findParent(b)
        
        if a < b:
            parent[b] = a 
        else:
            parent[a] = b 
    
    for cost in costs:
        a, b, c = cost
        if findParent(a) != findParent(b):
            unionParent(a, b)
            answer += c 
    
    return answer

print(solution(4, [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))