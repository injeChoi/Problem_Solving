import math

def solution(n):
    answer = 0
    isPrime = [True] * (n+1)
    isPrime[0], isPrime[1] = False, False

    for i in range(2, int(math.sqrt(n)+1)):
        if isPrime[i] == False:
            continue
        for j in range(i+i, n+1, i):
            isPrime[j] = False

    for i in range(1, n+1):
        if isPrime[i]:
            answer += 1

    return answer
