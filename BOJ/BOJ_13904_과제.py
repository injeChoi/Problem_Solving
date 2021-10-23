N = int(input())
work = [list(map(int, input().split())) for _ in range(N)]
work.sort(reverse=True)
MAX = work[0][0]
answer = 0

for i in range(MAX, 0, -1):
    tmp = []
    for j in range(len(work)):
        if i <= work[j][0]:
            tmp.append([work[j][1], j])
    if len(tmp) > 0:
        tmp.sort(reverse=True)
        answer += tmp[0][0]
        del work[tmp[0][1]]

print(answer)