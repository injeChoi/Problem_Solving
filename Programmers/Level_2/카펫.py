'''
https://programmers.co.kr/learn/courses/30/lessons/42842

약수 구하기 + 약수 쌍 x, y 중 (x-2) * (y-2) = yellow 인 값 찾기 
(x-2) * (y-2) = yellow 를 구하는 이유
사각형 상하좌우(테두리) 칸을 뺀 나머지 칸들의 개수 합이 yellow 
'''

def solution(brown, yellow):
    answer = [0, 0]
    total = brown + yellow
    lst = [x for x in range(1, total + 1) if total % x == 0]

    for i in range(len(lst)):
        if (lst[i] - 2) * (lst[-i-1] - 2) == yellow:
            answer[0], answer[1] = lst[-i-1], lst[i]
            return answer

    return answer

print(solution(50, 22))