'''
https://programmers.co.kr/learn/courses/30/lessons/92342

Fail, DFS 더 공부 후 재도전
'''

from copy import deepcopy

def solution(n, info):
    visited = [0] * 11
    candidates = []
    target = 0
    
    def dfs(pos, arrow):
        nonlocal target, candidates, n
        
        if arrow == 0:
            total = 0
            apeach = 0

            for idx in range(11):
                if info[idx] > 0 and visited[idx] == 0:
                    apeach += 10 - idx
                if visited[idx] > 0:
                    total += 10 - idx
            
            if total > apeach and total >= target:
                target = total
                candidates = deepcopy(visited)
                
            return
        
        for i in range(pos, len(info)):
            if not visited[i] and arrow > info[i]:
                visited[i] = info[i] + 1
                
                if info[i] == 0:
                    dfs(i, arrow - 1)
                else:
                    dfs(i, arrow - info[i] - 1)
                    
                visited[i] = 0

        print(visited)
        if arrow > 0:
            visited[i] = arrow
            dfs(i, 0)
                
    dfs(0, n)
    
    if len(candidates) == 0:
        return [-1]
    return candidates

print(solution(10, [0,0,0,0,0,0,0,0,3,4,3]))