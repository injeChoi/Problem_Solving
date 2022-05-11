'''
https://www.acmicpc.net/problem/5430

reverse 연산을 매번 실행하면 시간 초과가 난다
고로, reverse 연산을 최소화하기 위해 연속되는 R의 개수를 센 후 
2로 나머지 연산을 해서 실제로 뒤집을지 말지 판별한다
하지만 이렇게 해도 시간 초과를 피할 수 없다

뒤집어야 하는 상황이 있더라도 실제로 뒤집는게 아니라
맨 앞의 원소를 삭제하는게 아니라 맨 뒤의 원소를 삭제하면 된다

R의 개수를 누적해서 세면서 누적 값이 홀수이면 맨 뒤 원소 삭제, 짝수면 맨 앞 원소 삭제인 것이다
모든 R그룹 내의 R의 개수를 세서 홀수이면 배열을 뒤집어서 출력해야 한다 
'''

from collections import deque

T = int(input())

def solution():
    functions = input()
    n = int(input())
    s = input()[1:-1]
    if s:
        arr = deque(map(int, s.split(",")))
    else:
        arr = []
    tmp = []
    flag = True
    r_cnt = 0
        
    def divide():
        nonlocal tmp
        prev = functions[0]
        cnt = 0
        
        for idx, function in enumerate(functions):
            if function != prev:
                tmp += [[cnt, prev]]
                prev = function
                cnt = 0
            
            cnt += 1
            
            if idx == len(functions)-1:
                tmp += [[cnt, function]]
        
    def logic():
        nonlocal flag, r_cnt
        
        for num, func in tmp:
            if func == 'R':
                r_cnt += num
                if r_cnt % 2 == 1:
                    flag = False
                else:
                    flag = True
            
            elif func == 'D':
                for _ in range(num):
                    if arr:
                        if flag:
                            arr.popleft()
                        else:
                            arr.pop()
                    else:
                        return -1
    
    def pretty():
        if not arr:
            return '[]'
        
        if r_cnt % 2 == 1:
            arr.reverse()
        
        return f"[{','.join(map(str, arr))}]"
        
    divide()

    if logic() == -1:
        print("error")
    else:
        print(pretty())
    
for _ in range(T):
    solution()
