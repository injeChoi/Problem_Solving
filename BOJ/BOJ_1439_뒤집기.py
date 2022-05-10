'''
https://www.acmicpc.net/problem/1439

실제로 문자열을 변화시킬 필요는 없고
1이 연속되는 그룹의 개수와 0이 연속되는 그룹의 개수를 세서
둘 중 작은 값 찾으면 된다
'''

S = input()
previous = ''
cnt_arr = [0, 0]

def check():
    if c == "0":
        cnt_arr[0] += 1
    else:
        cnt_arr[1] += 1

for c in S:
    if c != previous:
        check()
    previous = c
    
print(min(cnt_arr))