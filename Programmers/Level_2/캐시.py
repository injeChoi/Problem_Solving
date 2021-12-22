'''
https://programmers.co.kr/learn/courses/30/lessons/17680

덱을 활용해 LRU를 간단하게 구현
이미 cache 메모리 안에 있는 city가 중복으로 cache에 존재할 수 없다.
즉, cache hit를 검사하여 중복된 값이 있다면 기존 값을 제거하고 cache의 뒤에 추가한다.
'''

from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque()

    for city in cities:
        city = city.upper()

        if city in cache:
            answer += 1
            cache.remove(city)
        else:
            answer += 5
        if len(cache) < cacheSize:
            cache.append(city)
        else:
            if len(cache) > 0:
                cache.popleft()
            if len(cache) < cacheSize:
                cache.append(city)

    return answer

