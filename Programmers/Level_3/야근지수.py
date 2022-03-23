'''
https://programmers.co.kr/learn/courses/30/lessons/12927

그냥 정렬 메커니즘으로 풀면 시간 초과가 발생
고로 dictionary 자료구조 활용

배열 안에 1이 몇개 있는지 2가 몇개 있는지 n이 몇개 있는지 카운팅을 한다
ex) [3, 2, 5, 5] -> {3: 1, 2: 1, 5: 2}

여기서 5가 가장 큰 원소이니까 5을 먼저 감소 시켜야한다
하지만 5라는 원소는 2개 있으니, 2개 중 1개를 감소 시키면 
{3: 1, 2: 1, 5: 1, 4: 1} 이런 결과가 나온다
즉, dictionary에 n-1의 값을 key 값으로 갖는 원소를 생성 / 추가해야 한다

아직 야근 시간이 남았으면 또다시 가장 큰 원소를 감소 시킴
그러면 이번에도 5를 감소 시키게 돼서 4가 2개 생긴다
{3: 1, 2: 1, 4: 2}

이러한 과정을 통하면 배열에서 항상 가장 큰 수를 찾는 O(N)의 시간복잡도를 O(1)로 단축시킬 수 있고
가장 큰 원소들 부터 차근차근 줄여나가는 메인 로직은 유지할 수 있다
'''
from collections import defaultdict

def solution(n, works):
    answer = 0
    d = defaultdict(int)

    for work in works:
        d[work] += 1
 
    for item in range(max(works), 0, -1):
        if item in d.keys():
            while d[item] and n:
                d[item] -= 1
                d[item-1] += 1
                n -= 1

    for item in d.keys():
        if d[item] != 0:
            for _ in range(d[item]):
                answer += item ** 2

    return answer

# print(solution(4, [4,3,3]))