N = int(input())
arr = [0]
for i in range(N):
    arr.append(int(input()))
result = []

def dfs(current, start):
    if visited[current] == 1:
        if current == start:
            result.append(start)
    else:
        visited[current] = 1
        dfs(arr[current], start)
    
for i in range(1, N+1):
    visited = [0] * (N+1)
    dfs(i, i)

print(len(result))
for res in result:
    print(res)