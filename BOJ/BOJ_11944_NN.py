N, M = input().split()
M = int(M)
idx = 0

if len(N * int(N)) <= M:
    print(N * int(N))
else:
    if len(N) < M:
        while len(N) < M:
            if idx < len(N):
                N += N[idx]
                idx += 1
            if idx >= len(N):
                idx = 0
        print(N)
    else:
        for i in range(M):
            print(N[i], end='')
