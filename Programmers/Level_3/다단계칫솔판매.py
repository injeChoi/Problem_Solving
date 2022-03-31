'''
https://programmers.co.kr/learn/courses/30/lessons/77486

다단계에 끌어들인 사람 A, 끌어들여진 사람을 B라고 할 때
A와 B의 관계를 설정 후 저장 (양방향이 아님)
판매 금액을 확인한 후 자기 위에 누가 있는지 계속 체크해가면서
줘야할 돈이 1원 미만이거나, 위에 사람이 없을 때 까지 수수료 때이는 로직 실행 
'''

from collections import defaultdict

def solution(enroll, referral, seller, amount):
    answer = []
    relationship = defaultdict(str)
    hierarchy = defaultdict(int)
    
    for enr, ref in zip(enroll, referral):
        relationship[enr] = ref
        
    def recu(person, money):
        give = money // 10
        take = money - give
        hierarchy[person] += take
        
        if relationship[person] == "-" or give == 0:
            return

        recu(relationship[person], give)
        
    for person, m in zip(seller, amount):
        money = m * 100
        recu(person, money)
    
    for name in enroll:
        answer.append(hierarchy[name])
    
    return answer

print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"], 
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"], 
               ["young", "john", "tod", "emily", "mary"], 
               [12, 4, 2, 5, 10]))