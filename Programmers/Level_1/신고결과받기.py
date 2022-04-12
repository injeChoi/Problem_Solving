'''
https://programmers.co.kr/learn/courses/30/lessons/92334

여러 자료구조를 적절히 사용하면 쉽게 풀 수 있는 문제
'''

from collections import defaultdict

def solution(id_list, report ,k):
    answer = []
    received = defaultdict(int)
    int_dic = defaultdict(int)
    list_dic = defaultdict(list)
    s = set()
    
    for name in id_list:
        received[name] = 0
    
    for r in report:
        if r not in s:
            s.add(r)
            p1, p2 = r.split()
            int_dic[p2] += 1
            list_dic[p1] += [p2]
            
    for key, value in int_dic.items():
        if value >= k:
            for name, lst in list_dic.items():
                if key in lst:
                    received[name] += 1
                    
    for name in id_list:
        answer += [received[name]]
        
    return answer

print(solution(["muzi", "frodo", "apeach", "neo"],
               ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"],
               2))