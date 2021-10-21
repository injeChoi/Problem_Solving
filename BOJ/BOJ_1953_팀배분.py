import sys
sys.setrecursionlimit(10**6)

N = int(input())
tree = [[] for _ in range(N+1)]
visited = [0] * (N+1)
blue = []
white = []

for i in range(1, N+1):
    info = list(map(int, input().split()))
    for j in range(1, len(info)):
        tree[i].append(info[j])
        tree[info[j]].append(i)

def dfs(e, team):
    visited[e] = team
    for i in range(len(tree[e])):
        nxt = tree[e][i]
        if not(visited[nxt]):
            dfs(nxt, -team)

for i in range(1, N+1):
    if not(visited[i]):
        dfs(i, 1)

for i in range(1, N+1):
    if visited[i] == 1:
        blue.append(i)
    elif visited[i] == -1:
        white.append(i)

blue.sort()
white.sort()
print(len(blue), ' '.join(map(str, blue)), sep='\n')
print(len(white), ' '.join(map(str, white)), sep='\n')