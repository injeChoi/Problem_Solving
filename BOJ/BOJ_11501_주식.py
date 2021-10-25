import sys
input = sys.stdin.readline

for _ in range(int(input())):
    answer = 0
    day = int(input())
    st = list(map(int, input().split()))
    MAX = 0
    for i in range(len(st)-1, -1, -1):
        if MAX < st[i]:
            MAX = st[i]
        else:
            answer += MAX - st[i]
    print(answer)