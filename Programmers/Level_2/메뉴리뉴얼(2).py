'''
https://programmers.co.kr/learn/courses/30/lessons/72411

각각의 손님이 주문한 단품메뉴 조합을 정렬 후 조합을 구하는게 핵심
정렬하지 않고 조합을 구하면 'WX'를 주문한 것과 'XW'를 주문한 것을 별개로 친다
주문 순서에 상관하지 않아야 하기 때문에 정렬을 해야한다 

그렇게 만들어진 조합을 리스트에 저장하고 
각 음식 조합별로 개수를 센다
음식 조합의 개수가 가장 많은 녀석들을 정답 리스트에 추가한다

최종적으로 정답 리스트를 정렬 후 리턴한다 
'''

from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []
    foods = []

    def make_combinations(num):
        for order in orders:
            lst = list(combinations(sorted(order), num))
            for item in lst:
                foods.append(''.join(item)) 
                
    def find_max():
        if not foods:
            return
        
        counter = Counter(foods)
        MAX = max(counter.values())
        if MAX > 1:
            tmp = list(filter(lambda x: x[1] == MAX, counter.items()))
            for key, value in tmp:
                answer.append(key)
                
    for c in course:
        foods = []
        make_combinations(c)
        find_max()

    return sorted(answer)

print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))