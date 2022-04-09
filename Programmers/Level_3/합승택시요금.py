'''
https://programmers.co.kr/learn/courses/30/lessons/72413?language=python3

전형적인 플로이드 워셜 알고리즘 문제
모든 최소 경로를 구한 후
s -> v, v -> A, v -> B 까지의 가중치를 합산해서 최솟값 찾으면 끝 

주의할 점은 플로이드 워셜 알고리즘의 시간복잡도가 O(N^3)이기 때문에 
V의 값이 1000 정도만 되도 시간 초과에 걸릴 수 있다

하지만 이 문제에서 N의 최댓값이 200이기 때문에 위 알고리즘을 적용해도 된다 
'''

def solution(n, s, a, b, fares):
    INF = int(1e9)
    answer = INF
    graph = [[INF] * (n + 1) for _ in range(n + 1)]
    
    def make_graph():
        for i in range(1, n+1):
            graph[i][i] = 0
            
        for s, e, c in fares:
           graph[s][e] = c
           graph[e][s] = c
    
    def floyd_warshall():
        for k in range(1, n+1):
            for i in range(1, n+1):
                for j in range(1, n+1):
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    
    make_graph()
    floyd_warshall()
    
    for v in range(1, n+1):
        together = graph[s][v] + graph[v][a] + graph[v][b]
        answer = min(answer, together)

    return answer

print(solution(6,4,6,2,
               [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], 
                [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))