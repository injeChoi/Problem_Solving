'''
https://programmers.co.kr/learn/courses/30/lessons/12914

DFS 시간 초과
피보나치랑 동일한 로직으로 처리 가능
n = 1 : 1 가지
n = 2 : 2 가지
n = 3 : 3 가지
n = 4 : 5 가지
n = 5 : 8 가지
'''

def solution(n):
    memo = [1, 2]

    for i in range(2, n):
        memo.append((memo[i-1] + memo[i-2]) % 1234567)

    return memo[n-1]

print(solution(1))