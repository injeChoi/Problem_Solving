'''
https://programmers.co.kr/learn/courses/30/lessons/12936

itertools의 permutation으로 풀면 n의 최대가 20이기 때문에 시간 초과 O(N!)

수학적인 방법으로 접근

NOTE: 순열 그룹
사람 3명이 줄을 서는 순열을 다음과 같이 나타낼 때
[
    [1,2,3], [1,3,2],
    [2,1,3], [2,3,1],
    [3,1,2], [3,2,1]
]
11번째 줄을 그룹1, 12번째 줄을 그룹2, 13번째 줄을 그룹3이라고 가정하고 풀이 진행
즉, group[0] = 1, group[1] = 2, group[2] = 3

(n-1)!로 k를 나눠보면 순열 그룹의 index를 찾을 수 있다

ex) n = 4, k = 7 일 때
7 / 3! = 1...1 이다. 이때 몫은 줄 서는 방법은 몇 번째 그룹에 속하는 지를 나타내고
나머지는 다음 줄서는 사람을 구할 때 사용된다.
즉, 이 때는 줄 서는 방법은 group[1] = 2로 시작한다는 의미

구한 값(group[1] = 2)을 answer 리스트에 추가하고 group[1]를 group 리스트에서 제거
즉, 기존 answer = [], group = [1, 2, 3, 4]에서 answer = [2], group = [1, 3, 4]

방금 구한 값은 7 / 3! = 1...1 이다. 즉, 몫: 1, 나머지: 1
다음 줄 설 사람을 찾는 것은 나머지 값을 활용한다

총 4인 중 1명은 줄을 섰으니 남은 3명만 줄을 세우면 된다
방금 구한 나머지 값에서 (4-1)!을 나눠줘서 다음 줄 설 사람이 어떤 그룹에 속한지 찾는다
즉, 1 / 3! = 0...1 이므로 다음 줄 설 사람은 group[0] = 1 이다
고로, answer = [2, 1], group = [3, 4]

다시 나머지 값에 (4-2)!을 나눠서 다음 사람을 구하면
1 / 2! = 0...1 이므로 다음 사람은 group[0] = 3 이다
고로, answer = [2, 1, 3], group = [4]

다시 나머지 값에 (4-3)!을 나눠서 다음 사람을 구하면
1 / 1! = 1...0 이므로 다음 사람은 group[1] = Out of Index 오류가 발생한다
고로 나머지가 0이면 구한 몫에 -1을 한 값을 index로 삼는다
즉, group[1-1] = 4 이므로
answer = [2, 1, 3, 4], group = [] 가 된다.
'''

from math import factorial

def solution(n, k):
    answer = []
    lst = [x for x in range(1, n+1)]

    while n:
        f = factorial(n-1)
        quotient, remainder = int(k // f), k % f

        if remainder == 0:
            answer.append(lst.pop(quotient-1))
        else:
            answer.append(lst.pop(quotient))

        n -= 1
        k = remainder

    return answer

print(solution(4, 7))