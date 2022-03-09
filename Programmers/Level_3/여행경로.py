'''
https://programmers.co.kr/learn/courses/30/lessons/43164

stack으로 DFS 하는 방법 
'''

from collections import defaultdict

def solution(tickets):
    answer = []

    # 예정지 목록 
    d = defaultdict(list)

    for item in tickets:
        d[item[0]].append(item[1])

    # 오름차순으로 정렬하면 pop 연산 대신 remove 연산을 해야돼서 O(n) 시간이 걸리니까
    # 내림차순으로 정렬해서 pop 연산을 통해 사전 순으로 가장 앞에 있는걸 O(1) 시간으로 제거 
    for key in d:
        d[key].sort(reverse=True)

    # 목적지 목록 
    stack = ['ICN']

    while stack:
        # 다음 목적지 
        top = stack[-1]

        # 만약 목적지에서 또 다른 공항으로 넘어갈 수 없다면 
        # 더이상 이 경로를 통해 갈 수 있는 곳이 없으니 정답에 추가 
        if not d[top]:
            answer.append(stack.pop())
        
        # 목적지 목록에 추가하고 예정지에선 제거 
        else:
            stack.append(d[top].pop())

    # 위에서 내림차순 정렬을 했었으니 다시 오름차순으로 정렬해서 리턴 
    return list(reversed(answer))
