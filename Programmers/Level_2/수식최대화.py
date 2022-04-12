'''
https://programmers.co.kr/learn/courses/30/lessons/67257

[*, +, -] 3개의 연산자를 우선순위를 다르게해서 만들 수 있는 우선순위 조합 생성
각각의 우선순위마다 수식 계산 후 값 저장

How?
예를 들어 우선순위가 [*, +, -] 일 때,
수식에서 * 연산만 수행 후 남은 수식에서 +, - 차례로 계산 
결괏값을 배열에 저장
다음 우선순위가 [+, *, -] 이면,
수식에서 + 연산만 수행 후 남은 수식에서 *, - 차례로 계산
결괏값 저장 
이런식으로 총 6개의 우선순위에 따라 계산 진행 후 절댓값이 가장 큰 결괏값 리턴 
'''

from itertools import permutations
from collections import deque

def solution(expression):
    answer = []
    operators = ["+", "-", "*"]
    pm = list(permutations(operators, 3))
    
    def calculate(ops):
        remaining_exp = deque()
        operand = ""
        
        for e in expression:
            if e.isdigit():
                operand += e
            else:
                remaining_exp.append(operand)
                remaining_exp.append(e)
                operand = ""
                
        remaining_exp.append(operand)
        
        for target_op in ops:
            calculated = deque()
            
            while len(remaining_exp):
                exp_member = remaining_exp.popleft()
                if exp_member == target_op:
                    result = str(eval(calculated.pop() + target_op + remaining_exp.popleft()))
                    calculated.append(result)
                else:
                    calculated.append(exp_member)
                    
            remaining_exp = calculated
            
        return remaining_exp.popleft()
    
    for priority in pm:
        answer += [abs(int(calculate(priority)))]
 
    return sorted(answer)[-1]

print(solution("50*6-3*2"))