from itertools import permutations

def solution(numbers):
    answer = 0
    lst = set()
    numbers = list(numbers)
    numbers.sort(reverse=True)
    dec = int(''.join(numbers))
    is_prime = [0, 0] + [1] * dec

    for i in range(2, int((dec**0.5)+1)):
        if is_prime[i] == 0:
            continue
        for j in range(i+i, dec+1, i):
            is_prime[j] = 0
    
    for i in range(1, len(numbers)+1):
        pmt = list(permutations(numbers, i))
        for item in pmt:
            string = ''.join(item)
            lst.add(int(string))

    for item in lst:
        if is_prime[int(item)] == 1:
            answer += 1

    return answer