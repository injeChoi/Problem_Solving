from collections import deque

def solution(priorities, location):
    answer = 1
    q = deque()

    for i, item in enumerate(priorities):
        q.append((item, i))

    while q:
        m = max(q, key=lambda x:x[0])
        if q[0][0] == m[0]:
            if q[0][1] == location:
                break
            else:
                q.popleft()
                answer += 1
        else:
            q.append(q[0])
            q.popleft()

    return answer

solution([2, 1, 3, 2], 2)