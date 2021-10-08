N, L = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
path = 0

def rotate():
    tmp = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            tmp[N-1-j][i] = graph[i][j]

    return tmp

def check():
    global path
    for row in graph:
        slope = [0] * N
        flag = True
        flat = 1
        for i in range(1, len(row)):
            if row[i] == row[i-1]:
                flat += 1
            else:
                if row[i] - row[i-1] > 0:
                    if row[i] - row[i-1] > 1 or flat < L or slope[i-L]:
                        flag = False
                        break
                    else: 
                        slope[i-L:i] = [1] * L
                        flat = 1

                if row[i] - row[i-1] < 0:
                    if row[i] - row[i-1] < -1:
                        flag = False
                        break

                    flat = 1
                    if i + L - 1 < N:
                        j = i
                        desc = 0
                        while row[i] == row[j]:
                            desc += 1
                            j += 1
                            if j >= N: break

                        if desc >= L:
                            slope[i:i+L] = [1] * L
                        else:
                            flag = False
                            break
                    else:
                        flag = False
                        break
        if flag: 
            path += 1

check()
graph = rotate()
check()
print(path)