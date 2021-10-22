N, L = map(int, input().split())
tapes = list(map(int, input().split()))
cnt = i = 0
tapes.sort()

if L == 1:
    print(len(tapes))
else:
    while i < len(tapes):
        j = i + 1
        while j < len(tapes):
            if tapes[j] - tapes[i] > L - 1:
                cnt += 1
                i = j-1
                break
            j += 1
        i += 1
    print(cnt+1)