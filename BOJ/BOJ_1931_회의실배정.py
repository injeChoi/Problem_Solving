N = int(input())
conf = [list(map(int, input().split())) for _ in range(N)]
conf.sort(key=lambda x:(x[1], x[0]))
last = conf[0][1]
cnt = 1

for i in range(1, N):
    if conf[i][0] >= last:
        cnt += 1
        last = conf[i][1]

print(cnt)