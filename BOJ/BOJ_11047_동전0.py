N, K = map(int, input().split())
value = [int(input()) for _ in range(N)]
cnt = 0

for i in range(len(value)-1, -1, -1):
    if value[i] <= K:
        cnt += K // value[i]
        K %= value[i]

print(cnt)