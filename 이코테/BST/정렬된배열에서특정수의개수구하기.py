from bisect import bisect_left, bisect_right

N, x = map(int, input().split())
arr = list(map(int, input().split()))

result = bisect_right(arr, x) - bisect_left(arr, x)

if result == 0:
    print(-1)
else:
    print(result)
