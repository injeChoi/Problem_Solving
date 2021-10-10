from collections import deque

N = int(input())
population = list(map(int, input().split()))
con = [[] for _ in range(N)]
MIN = 10e8

# 선거구가 이어져있는지 확인
def bfs(g):
    q = deque()
    check = [0 for _ in range(N)]
    q.append(g[0])
    check[g[0]] = 1
    cnt, ans = 1, 0

    while q:
        x = q.popleft()
        ans += population[x]
        for nx in con[x]:
            if nx in g and check[nx] == 0:
                check[nx] = 1
                cnt += 1
                q.append(nx)
    
    return ans if cnt == len(g) else 0

# 지역 구분하기 
def dfs(cnt, x, end):
    global MIN
    if cnt == end:
        # 지역 두개 생성 
        g1, g2 = deque(), deque()
        for i in range(N):
            if c[i]: g1.append(i)
            else: g2.append(i)

        ans1 = bfs(g1)
        if not ans1: return

        ans2 = bfs(g2)
        if not ans2: return

        MIN = min(MIN, abs(ans2-ans1))
        return

    # 다음 선거구 추가 
    for i in range(x, N):
        if c[i]:
            continue
        c[i] = 1
        dfs(cnt+1, i, end)
        c[i] = 0

for i in range(N):
    lst = list(map(int, input().split()))
    for j in range(1, lst[0]+1):
        con[i].append(lst[j]-1)

# 선거구 하나씩 늘리기 
for i in range(1, N//2+1):
    # 어떤 선거구가 지역에 들어갔는지 체크 
    c = [0 for _ in range(N)]
    dfs(0, 0, i)

print(-1) if MIN == 10e8 else print(MIN)