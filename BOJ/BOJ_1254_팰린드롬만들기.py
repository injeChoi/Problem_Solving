# 앞에서 부터 문자를 하나씩 제거해가며 부분 문자열이 팰린드롬인 지점을 찾는다. 
# 문자열 + 팰린드롬 아닌 부분 뒤집어서 붙이면 끝  

S = input()

def check(s):
    r = s[::-1]
    for i in range(len(s)//2):
        if s[i] != r[i]:
            return 0
    return 1

for i in range(len(S)):
    if check(S[i:]):
        print(len(S) + i)
        break

