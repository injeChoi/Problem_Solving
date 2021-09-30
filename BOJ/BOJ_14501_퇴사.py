N = int(input())
TP = [list(map(int, input().split())) for _ in range(N)]
dp = [-1] * (15)
total = 0

# DP
def solve(day):
    if (day > N): return -987654321
    if (day == N): return 0
    
    ret = dp[day]
    if ret != -1: return ret
    ret = max(solve(day+1), solve(day+TP[day][0]) + TP[day][1])
    return ret

print(solve(0))

# DFS
def dfs(day, money):
    global total

    if day == N:
        total = max(total, money)
        return
    elif day > N:
        return
    # 상담 안 하는 경우 
    dfs(day+1, money)
    # 기간 내에 상담할 수 있는 경우 
    if day + TP[day][0] <= N:
        dfs(day+TP[day][0], money+TP[day][1])

dfs(0, 0)
print(total)