def solution(n):
    answer = ''
    # 1씩 빠진 값의 3진법인데 0,1,2가 아닌 1,2,4가 들어가야 한다.
    while n > 0:
        n -= 1
        answer = '124'[n % 3] + answer
        n //= 3

    return answer