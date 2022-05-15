'''
https://www.acmicpc.net/problem/14888

최대 11! 의 시간 복잡도가 걸리는 극악의 솔루션 
연산자들의 모든 순열을 구한 후 중복 제거, 
구한 연산 순서로 일일이 계산 후 최대 최소 값 계산
아마 모든 결괏값들을 저장 후 정렬 후 최종 답안을 도출했으면
시간 초과가 났을 거 같다.

개선 방안으로는 
dfs를 진행할 때 미리 만들어둔 연산자 배열(operators)에 방문처리 로직을 추가한다
연산자 하나 쓰면서 dfs 호출하고
호출 종료되면 해당 연산자 방문처리를 제거하는 방식으로 솔루션을 만들면
시간적으로 매우 효율적이다 
'''

N = int(input())
numbers = list(map(int, input().split()))
counters = list(map(int, input().split()))
operators = []
for idx, cnt in enumerate(counters):
    operators += [idx+1] * cnt
length = len(operators)
visited = [0] * length
p_list = set()
MIN, MAX = int(1e9), -int(1e9)

def dfs(lst):
    if len(lst) == length:
        p_list.add(tuple(lst))
        return
    
    for i in range(length):
        if not visited[i]:
            visited[i] = 1
            dfs(lst+[operators[i]])
            visited[i] = 0

def distinguish(operand1, element, operand2):
    if element == 1:
        return operand1 + operand2
    elif element == 2:
        return operand1 - operand2
    elif element == 3:
        return operand1 * operand2
    else:
        if operand1 < 0 or operand2 < 0:
            return -(abs(operand1) // abs(operand2))
        return operand1 // operand2

def calculate():
    global MIN, MAX
    result = numbers[0]
    
    for idx, op in enumerate(operator):
        result = distinguish(result, op, numbers[idx+1])
        
    MIN = min(MIN, result)
    MAX = max(MAX, result)
        
dfs([])

for operator in p_list:
    calculate()
    
print(MAX)
print(MIN)