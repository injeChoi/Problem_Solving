H, W = map(int, input().split())
block = list(map(int, input().split()))
left = right = cnt = 0

if len(block) == 1:
    print(0)
else:
    for i in range(1, W):
        left = block[i]
        right = block[i]
        # 현재 인덱스의 값 보다 큰게 있나 탐색 
        for j in range(i):
            left = max(left, block[j])
        for j in range(i+1, W):
            right = max(right, block[j])

        cnt += min(left, right) - block[i]

    print(cnt)