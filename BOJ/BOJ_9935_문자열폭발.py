'''
https://www.acmicpc.net/problem/9935

문자열 S의 최대 길이가 100만이므로 단순히 매번 find와 replace 연산을 통해
처리를 하면 시간 초과가 발생한다

고로 문자열의 문자를 스택에 하나씩 추가하다가 
만약 스택에 가장 최근에 쌓인 문자열이 폭탄과 같다면 스택에서 폭탄을 제거한다 
'''

S = input()
bomb = input()
l = len(bomb)
st = []

for c in S:
    st += [c]
    if len(st) >= l and ''.join(st[-l:]) == bomb:
        for i in range(l):
            st.pop()

if not st:
    print("FRULA")
else:
    print(''.join(st))

  