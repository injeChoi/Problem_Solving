'''
https://programmers.co.kr/learn/courses/30/lessons/76502

회전하는 큐를 구현하는 방법과
서로 다른 괄호 모양들 예외처리가 중점
'''


def solution(s):
    answer = 0
    idx = 0

    while idx < len(s):
        lst = []
        flag = False
        tmp = s
        tmp = tmp[idx:] + tmp[:idx]
        idx += 1

        for i in range(len(tmp)):
            if tmp[i] in ['(', '{', '[']:
                lst.append(tmp[i])
            else:
                if len(lst) > 0:
                    if tmp[i] == ')' and lst[-1] == '(':
                        lst.pop()
                    elif tmp[i] == '}' and lst[-1] == '{':
                        lst.pop()
                    elif tmp[i] == ']' and lst[-1] == '[':
                        lst.pop()
                    else:
                        break
                else:
                    break
        else:
            if len(lst) != 0:
                flag = False
            else: 
                flag = True
        
        if flag:
            answer += 1

    return answer

solution("{{{{{{")