'''
https://programmers.co.kr/learn/courses/30/lessons/86971

간선을 하나씩 제거하여 전력망을 2개로 나누고
DFS를 통해 전력망 안에 있는 송전탑 개수를 센다.

2개로 분리된 전력망에 대한 정보를 connect 리스트에 담고
DFS에서 방문한 노드를 확인하기 위해 visited 리스트를 사용한다.

DFS 함수에서 특정 전력망에서 방문한 송전탑의 개수를 리턴한다.
2개의 전력망에서 송전탑 개수 차이가 가장 적을 값을 리턴한다.
'''


def solution(n, wires):
    answer = 10e6
    idx = 0
    length = len(wires)

    # 전력망 안에 몇개의 송전탑이 있는지 리턴 
    def dfs(idx):
        visited[idx] = 1
        for node in connect[idx]:
            if not visited[node]:
                lst.append(node)
                dfs(node)

        return len(lst)

    # 특정 간선 제거하여 connect 리스트에 정보 추가 
    while idx < length:
        connect = [[] for _ in range(n + 1)]
        visited = [0] * (n + 1)

        for i in range(length):
            # 특정 간선 제거 로직 
            if i == idx:
                continue
            # 간선은 양방향으로 처리 
            connect[wires[i][0]].append(wires[i][1])
            connect[wires[i][1]].append(wires[i][0])

        # 전력망 안에 몇개의 송전탑이 있는지 저장할 리스트 
        cnt = []

        # 방문 안 한 송전탑이 있다면 해당 송전탑을 포함한 전력망 안에 송전탑 개수 찾기
        for i in range(1, n + 1):
            if not visited[i]:
                lst = [i]
                cnt.append(dfs(i))

        answer = min(answer, abs(cnt[0] - cnt[1]))
        idx += 1

    return answer
