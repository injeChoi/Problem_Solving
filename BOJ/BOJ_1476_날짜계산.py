E, S, M = map(int, input().split())
for i in range(1, 7981):
    if (i-E) % 15 == 0 and (i-S) % 28 == 0 and (i-M) % 19 == 0:
        print(i)
        break