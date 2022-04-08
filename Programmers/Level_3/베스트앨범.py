'''
https://programmers.co.kr/learn/courses/30/lessons/42579?language=python3

자료구조를 어떻게 나눠서 쓸지 고민하는데 시간이 많이 든 문제
(dictionary의 key와 value를 어떻게 설정할지, 
정렬이 꼭 필요하니 리스트가 필요한데 value를 list형으로 만드는게 맞을지 등)

genres와 plays의 길이가 10,000 이하로 작으니 2중 반복을 하더라도
최악의 경우에도 시간초과가 나지 않을것이니까 장르별로 값을 뽑아서 배열에 넣는 방식으로 풀이
'''

from collections import defaultdict

def solution(genres, plays):
    answer = []
    d = defaultdict(int)
    
    for i in range(len(genres)):
        d[genres[i]] += plays[i]
    
    tmp = sorted(d.items(), key= lambda x: x[1], reverse=True)

    for t in tmp:
        arr = []
        
        for i in range(len(genres)):
            if genres[i] == t[0]:
                arr.append([plays[i], i])
        
        arr.sort(key=lambda x: (x[0], -x[1]))
        
        if len(arr) > 1:
            p1, p2 = arr.pop(), arr.pop()
            answer += [p1[1], p2[1]]
        else:
            p1 = arr.pop()
            answer += [p1[1]]
    
    return answer

print(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]))