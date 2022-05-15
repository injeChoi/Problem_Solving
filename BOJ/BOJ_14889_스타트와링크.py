'''
https://www.acmicpc.net/problem/14889

시간 복잡도를 고려하면서 dfs를 만들어야 하는 문제
s_score, l_score를 구할 때 팀 별로 2명씩 짝지은 순열 대신 조합을 찾는 이유는
[0, 2]나 [2, 0]이나 능력치를 구할 때 상호 반대의 수를 쓰는 건 똑같이 때문이다
고로 순열을 조합으로 바꿈으로써 시간 복잡도를 1차적으로 낮출 수 있었고
팀 구성을 할 때 모든 조합을 구하면 S팀과 L팀의 구성원 들이 팀만 다르고 동일한 구성원으로 조합되는 경우가 있다
예를 들어 S팀에 (0,1,2,3), L팀에 (4,5,6,7)으로 구성되거나 L팀에 (4,5,6,7) S팀에 (0,1,2,3)으로
구성되는 것은 결국 같은 결과를 주게 되므로 이런 중복도 제거해야 한다 

하지만 현재 로직도 시간복잡도에서 크게 좋지는 못한 듯 하다
N / 2개가 방문처리 되면 방문한 놈들을 S팀, 아닌 놈들을 L팀에 넣고
바로 능력치 합산을 구해서 최솟값을 찾아가는 로직이 시간적으로 더 효율적이다 
'''

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
lst = [i for i in range(N)]
visited = [0] * N
c_list = []
v = []
answer = int(10e9)

def make_combination(idx, s, tmp):
    if len(tmp) == 2:
        c_list.append(tmp)
        return
    
    for i in range(idx, len(s)):
        make_combination(i + 1, s, tmp + [s[i]])

def calculate(s, l):
    global c_list, v, answer
    
    c_list = []
    v = [0] * len(s)
    make_combination(0, s, [])
    s_score = sum([(graph[y][x] + graph[x][y]) for y, x in c_list])
    
    c_list = []
    v = [0] * len(l)
    make_combination(0, l, [])
    l_score = sum([(graph[y][x] + graph[x][y]) for y, x in c_list])
    
    answer = min(answer, abs(s_score - l_score))

def dfs(idx, tmp):
    if len(tmp) == N // 2 and tmp[0] == 0:
        S = tmp[:]
        L = [i for i in range(N) if not visited[i]]
        calculate(S, L)
        return
    
    for i in range(idx, N):
        if not visited[i]:
            visited[i] = 1
            dfs(i + 1, tmp + [i])
            visited[i] = 0

dfs(0, [])
print(answer)