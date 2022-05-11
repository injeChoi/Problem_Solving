'''
https://www.acmicpc.net/problem/5525

100점을 맞기 위해선 시간 복잡도 고려가 필요한 문제

찾으려는 패턴을 pn이라 할 때,
전체 문자열에서 IOIOI....IOI 형태를 가진 부분 문자열을 찾은 후
(부분 문자열 길이 - pn 길이) / 2 + 1 을 하면 
부분 문자열 안에 pn이 몇 개 있는지 계산해낼 수 있다 

전체 문자열이 IOI 형태로 마무리되는 경우를 고려해서
부분 문자열이 ""으로 초기화되지 않은 경우 계산을 다시 한 번 해서 답을 추가해준다 
'''

N = int(input())
M = int(input())
S = input()
length = N * 2 + 1
pn = ""
tmp = ""
answer = 0

for i in range(length):
    if i % 2 == 0:
        pn += 'I'
    else:
        pn += 'O'

for i in range(M-1):
    if not tmp:
        if S[i] == 'I':
            tmp += 'I'
    
    if tmp:
        if S[i] != S[i+1]:
            tmp += S[i+1]
        else:
            result = len(tmp) - length
            if result >= 0:
                answer += result // 2 + 1
            tmp = ""
    
if tmp:
    result = len(tmp) - length
    if result >= 0:
        answer += result // 2 + 1

print(answer)