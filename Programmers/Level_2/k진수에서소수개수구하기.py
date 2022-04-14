'''
https://programmers.co.kr/learn/courses/30/lessons/92335

1. 소수 찾기 알고리즘 구현
2. 진수 전환 (앞부분의 0들 제거) 알고리즘 구현
3. 0 기준으로 split하면 0 앞 뒤로의 숫자들이 나옴
4. split된 숫자가 소수인지 판별 후 맞다면 답 1증가 
'''

def solution(n, k):
    answer = 0
    converted = ""
    
    def check_prime(num):
        if num == 1:
            return False
        
        for i in range(2, int(num**0.5)+1):
            if num % i == 0:
                return False
        return True
    
    def change_n():
        nonlocal n, k, converted
        
        while n > 0:
            n, mod = divmod(n, k)
            converted += str(mod)
        
        for idx, c in enumerate(converted):
            if c != "0":
                converted = converted[idx:]
                break
        
        converted = converted[::-1]
    
    change_n()
    lst = [int(x) for x in converted.split("0") if x != ""]

    for l in lst:
        if l != "":
            if check_prime(l):
                answer += 1

    return answer

print(solution(110011, 10))