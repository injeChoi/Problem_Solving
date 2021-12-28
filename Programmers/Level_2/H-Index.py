'''
https://programmers.co.kr/learn/courses/30/lessons/42747

i를 논문 인용 수 라고 생각하고 해결
right에 i회 이상 인용 된 논문이 들어감
right 원소 개수가 i이상이면 i는 답 후보
가장 큰 답이 리턴된다.
'''

def solution(citations):
    answer = 0
    citations.sort()

    for i in range(1, len(citations) + 1):
        right = [citations[x] for x in range(len(citations)) if citations[x] >= i]

        if len(right) >= i:
            answer = i

    return answer