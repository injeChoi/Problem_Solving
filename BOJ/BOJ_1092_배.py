N = int(input())
crane = list(map(int, input().split()))
M = int(input())
box = list(map(int, input().split()))
crane.sort(reverse=True)
box.sort(reverse=True)
cnt = 0

if crane[0] < box[0]:
    print(-1)
else:
    while box:
        for i in range(N):
            for j in range(len(box)):
                if crane[i] >= box[j]:
                    del box[j]
                    break
        cnt += 1

    print(cnt)