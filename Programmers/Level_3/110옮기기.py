'''
https://programmers.co.kr/learn/courses/30/lessons/77886

stack을 써서 선형시간 안에 '110'을 추출한다
'110'이 빠진 남은 문자열에서 뒤에서 부터 조사해서 0이 시작되는 곳을 찾고
해당 0 뒤에 110을 구한 개수만큼 붙여준다
마지막 110뒤에 원래 문자열을 덧붙인다
'''

def solution(s):
    answer = []
    
    for string in s:
        stack = []
        cnt = 0
        
        for c in string:
            if(len(stack) >= 2 and stack[-1] == '1' and stack[-2] == '1' and c == '0'):
                cnt += 1
                stack.pop()
                stack.pop()
            else:
                stack.append(c)
        
        tmp = ''.join(stack)
        idx = tmp.rfind("0")
        front, rear = tmp[:idx+1], tmp[idx+1:]
        front += "110" * cnt
        front += rear
        answer.append(front)
        
    return answer

print(solution(["100111100"]))