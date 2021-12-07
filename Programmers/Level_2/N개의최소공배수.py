from math import gcd

def solution(arr):
    answer = 1

    def lcm(x, y):
        return x * y // gcd(x, y)

    for item in arr:
        answer = lcm(answer, item)
        
    return answer

solution([2,6,8,14])