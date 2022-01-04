'''
https://programmers.co.kr/learn/courses/30/lessons/12978

heapq 모듈을 사용해 일반 리스트를 최소힙 처럼 사용가능 
다익스트라 알고리즘을 통해 1번 노드에서 타 노드로 가능 비용 계산
비용이 K 이상인 경우 제외한 개수 리턴 
'''

import heapq

def solution(N, road, K):
    INF = int(1e9)

    # start: 시작 노드 
    start = 1
    # 인접 노드 정보 
    graph = [[] for _ in range(N + 1)]
    # 최단 거리 테이블 
    distance = [INF] * (N + 1)

    # 간선 정보 입력
    for info in road:
        a, b, c = info
        # a에서 b로 가는 비용이 c (양방향)
        graph[a].append((b,c))
        graph[b].append((a,c))

    def dijkstra(start):
        q = []
        # 시작 노드로 이동하기 위한 거리는 0으로 세팅하고 큐에 넣기 
        heapq.heappush(q, (0, start))
        # 시작 노드에서 시작 노드로 가는 거리는 0 
        distance[start] = 0

        while q:
            # 지금까지 계산 된, 현재 노드에 도달하기 까지 가장 짧은 거리(dist)와 노드 번호(now) 
            dist, now = heapq.heappop(q)
            # 이미 최단 거리가 계산된 곳이라면 스킵
            if distance[now] < dist:
                continue
            # 현재 노드와 연결된 노드 확인
            for adjacent in graph[now]:
                # adjacent[0] = 도착 노드, adjacent[1] = 다음 노드로 가는 거리 (cost)
                cost = dist + adjacent[1]
                # 도착 노드를 거쳐서 가는게 기존 거리(거치지 않고) 보다 짧다면 교체
                if cost < distance[adjacent[0]]:
                    distance[adjacent[0]] = cost 
                    # 우선순위 큐에 도착 노드로 이동하는 최단 거리와 도착 노드 넣기 
                    heapq.heappush(q, (cost, adjacent[0]))

    # 다익스트라 알고리즘 수행 
    dijkstra(start)

    cnt = 0
    for i in range(1, N+1):
        if distance[i] <= K:
            cnt += 1

    return cnt
