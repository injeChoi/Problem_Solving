'''
https://programmers.co.kr/learn/courses/30/lessons/84512

Permutation과 Product 방식 모두 문제를 해결할 수 있다, 하지만 시간에서 차이가 크다.

Permutation의 경우 특정 원소를 중복으로 사용하지 않기 때문에
'A'를 5번 사용한 'AAAAA' 같은 문자열을 만들기 위해선 모음 리스트에 'A'를 5회 만들어놔야한다.

Product는 중복 순열로써 한 번 고른 것을 다시 고를 수 있다.

Permutaion은 모음 문자가 각 5개씩 있기 때문에
특정 문자열을 5 * (만드려는 문자열의 길이) 회씩 만든다.
예를 들어, 'AEIOU'라는 문자열을 만드려 하면
'A1EIOU', 'A2EIOU', ... , 'A5EIOU' 부터
'AEIOU1', 'AEIOU2', ... , 'AEIOU5'를 생성한다.

즉, Product가 만드는 조합의 개수보다 5 * (만드려는 문자열의 길이) 배의 개수를 생성한다. 
이는 곧 시간복잡도의 차이를 만든다.
'''

from itertools import permutations, product

# Not Recommended
def solution1(word):
    v = ['A', 'A', 'A', 'A', 'A', 
         'E', 'E', 'E', 'E', 'E', 
         'I', 'I', 'I', 'I', 'I', 
         'O', 'O', 'O', 'O', 'O', 
         'U', 'U', 'U', 'U', 'U']
    s = set()
    tmp = []

    for i in range(1, 6):
        lst = list(permutations(v, i))
        for l in lst:
            s.add(l)
    
    for item in s:
        tmp.append(list(item))

    tmp.sort()
    tmp = [''.join(x) for x in tmp]

    return tmp.index(word) + 1

# Recommended 
def solution2(word):
    v = ['A', 'E', 'I', 'O', 'U']
    lst = []

    for i in range(1, 6):
        lst.append(list(product(v, repeat = i)))
    
    lst = sum(lst, [])
    tmp = [''.join(list(x)) for x in lst]
    tmp.sort()

    return tmp.index(word) + 1
