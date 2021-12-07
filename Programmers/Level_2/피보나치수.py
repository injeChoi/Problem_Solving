import sys
sys.setrecursionlimit(1000001)

def solution(n):
    memo = [0] * 100001

    def fibo(num):
        if memo[num]:
            return memo[num]
        if num == 1:
            return 1
        if num == 0:
            return 0

        memo[num] = fibo(num-2) + fibo(num-1)
        return fibo(num-2) + fibo(num-1)
    
    return fibo(n) % 1234567

solution(5)