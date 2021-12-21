'''
https://programmers.co.kr/learn/courses/30/lessons/70129

이진 문자열을 다루는 연습을 하는게 문제의 의도
"0"을 지우고 난 후의 이진 값을 10진수로 바꾸는게 아니라
"0"을 지우고 난 후 남은 이진 문자열의 "길이"를 다시 s로 바꾸는 부분이 문제 명세에서 함정을 파둔 부분 
'''

def solution(s):
    cnt = 0
    removed = 0

    while s != "1":
        cnt += 1
        removed += s.count("0")
        s = ''.join([x for x in s if x == "1"])
        s = bin(len(s))[2:]

    return [cnt, removed]