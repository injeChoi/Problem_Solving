from collections import deque

def solution(begin, target, words):
    answer = cnt = 0
    visited = [False] * len(words)

    def bfs():
        q = deque()
        q.append((begin, cnt))
        
        while q:
            tmp, idx = q.popleft()
            if tmp == target:
                nonlocal answer
                answer = idx
                break

            for i, word in enumerate(words):
                if visited[i] == False:
                    # 다른 글자 개수가 1개이면 그 단어를 큐에 넣고 카운트 1 증가 
                    if [c1 == c2 for c1, c2 in zip(tmp, word)].count(False) == 1:
                        visited[i] = True 
                        q.append((word, idx+1))
                    
    bfs()
    return answer

solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"])