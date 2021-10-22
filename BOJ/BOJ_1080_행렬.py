N, M = map(int, input().split())
A = [list(map(int, input())) for _ in range(N)]
B = [list(map(int, input())) for _ in range(N)]
cnt = 0

def convert(y, x):
    for i in range(y, y+3):
        for j in range(x, x+3):
            A[i][j] = 1 - A[i][j]

def compare():
    for i in range(N):
        for j in range(M):
            if A[i][j] != B[i][j]:
                return False
    return True

if N >= 3 and M >= 3:
    for i in range(N-2):
        for j in range(M-2):
            if A[i][j] != B[i][j]:
                cnt += 1
                convert(i, j)

if compare():
    print(cnt)
else:
    print(-1)