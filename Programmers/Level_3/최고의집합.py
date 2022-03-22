'''
https://programmers.co.kr/learn/courses/30/lessons/12938

원소들 간의 차이가 최대한 작을 수록 모든 원소간의 곱 값이 가장 커진다
예를 들어 n = 4, s = 20 일 경우
[1, 1, 9, 9] 보다 [5, 5, 5, 5]의 곱 값이 더 크다
이러한 성질을 이용하면 s를 n으로 나눈 몫이 각각의 원소 값을 최대화 시킬 수 있는 1차적인 방법이고
s를 n으로 나눈 나머지를 원소에 1씩 더해주면 된다
'''

def solution(n, s):
    quotient, remainder = divmod(s, n)
    answer = [quotient] * n
    idx = len(answer) - 1

    if s < n:
        return [-1]
        
    for _ in range(remainder):
        answer[idx] += 1
        idx -= 1

    return answer

# print(solution(2, 7))