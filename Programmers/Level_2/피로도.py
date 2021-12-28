'''
https://programmers.co.kr/learn/courses/30/lessons/87946

DFS로 조합을 찾아 푸는 문제
처음에는 리스트 내림차순 정렬 후 풀어보려 했으나 로직이 지나치게 복잡해지는 문제 발생
visited라는 방문 처리 리스트를 활용하여 조합을 찾는다

k가 최소 필요 피로도보다 크면 그 던전을 탐사하러 가고 방문처리 한다.
특정 던전을 탐사한 경우로 답을 구했으면 
해당 던전을 탐사하지 않는 경우로 새로운 답을 구해본다
새로운 답이 기존 답 보다 크면 최신화한다. 
'''

def solution(k, dungeons):
    answer = -1
    l = len(dungeons)
    visited = [0] * l
    
    def dfs(k, cnt, dungeon):
        nonlocal answer, l
        if cnt > answer:
            answer = cnt
        
        for i in range(l):
            if k >= dungeon[i][0] and not visited[i]:
                visited[i] = 1
                dfs(k - dungeon[i][1], cnt + 1, dungeon)
                visited[i] = 0

    dfs(k, 0, dungeons)
    return answer

print(solution(80, [[80,20],[50,40],[30,10]]))