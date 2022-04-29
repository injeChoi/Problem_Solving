"""
https://www.acmicpc.net/problem/23290

상어는 방문했던 곳을 다시 갈 수 있다가 내가 놓친 핵심 포인트였다

상어는 인접한 칸을 격자 크기를 제외하고, 어떠한 제약없이 갈 수 있다
즉, 냄새, 물고기 존재 여부, 상어 자신이 방금 지나온 칸이 어딘지 상관하지 않는다
상어는 방문했던 곳을 다시 갈 수 있다는 점을 간과하여 TC 5, 6번을 계속 틀렸다
+ 상어는 방문했던 곳을 또 방문할 수 있기 때문에
상어가 지나온 곳에 있던 물고기를 제거하는 점도 꼼꼼히 살펴봐야 한다
상어가 원래 있던 자리에서 상,좌,우,하 순으로 움직임을 시작하고 dfs로 추후 움직임을 가져갈 위치를 파악하는데
상,좌,우,하 위치에 있던 물고기를 제거하지 않고 시작해놓고
dfs 함수에서만 물고기 제거 로직을 넣어놔서 이 부분을 수정하는데서 또 한참 걸렸다

그리고 문제 명세 아래 그림을 제대로 확인하지 않아서
냄새가 어느 시점에 줄어드는지 제대로 파악하지 않은 것도 문제였다

문제에서 요구하는 구현 사항이 굉장히 세세하고 많은 문제이기 때문에
역시 삼성 문제는 무턱대고 코딩을 진행하기 보단
종이에 설계를 꼼꼼히하고 문제 풀이에 돌입해야 한다는 점을 다시 한 번 깨달았다
"""

from copy import deepcopy

def solution():
    fy = [0, -1, -1, -1, 0, 1, 1, 1]
    fx = [-1, -1, 0, 1, 1, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    dx = [0, -1, 0, 1]
    M, S = map(int, input().split())
    graph = [[[] for _ in range(4)] for _ in range(4)]
    fish_pos = []
    shark_pos = []
    smell_graph = [[0] * 4 for _ in range(4)]
    smells = []
    answer = 0

    for _ in range(M):
        y, x, d = map(int, input().split())
        graph[y-1][x-1] += [d-1]
    sy, sx = map(int, input().split())
    sy, sx = sy - 1, sx - 1


    def replicate():
        nonlocal fish_pos
        fish_pos = []
        for i in range(4):
            for j in range(4):
                if graph[i][j]:
                    fish_pos += [[i, j, graph[i][j]]]


    def rotate(d):
        return (d - 1) % 8


    def can_fish_move(y, x):
        if 0 <= y < 4 and 0 <= x < 4 and smell_graph[y][x] == 0 and not (y == sy and x == sx):
            return True
        return False


    def move_fish():
        nonlocal graph
        tmp = [[[] for _ in range(4)] for _ in range(4)]

        for y in range(4):
            for x in range(4):
                if graph[y][x]:
                    for d in graph[y][x]:
                        for _ in range(8):
                            ny, nx = y + fy[d], x + fx[d]
                            if can_fish_move(ny, nx):
                                tmp[ny][nx] += [d]
                                break
                            else:
                                d = rotate(d)
                        else:
                            tmp[y][x] += [d]

        graph = tmp


    def dfs(y, x, pos, tmp_graph):
        nonlocal shark_pos

        if len(pos) > 2:
            shark_pos += [[sum([info[0] for info in pos]), [info[1] for info in pos]]]
            return

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]

            if 0 <= ny < 4 and 0 <= nx < 4:

                if not tmp_graph[ny][nx]:
                    dfs(ny, nx, pos + [[0, check_direction(dy[i], dx[i])]], tmp_graph)
                else:
                    graph_value = tmp_graph[ny][nx]
                    tmp_graph[ny][nx] = []
                    dfs(ny, nx, pos + [[len(graph_value), check_direction(dy[i], dx[i])]], tmp_graph)
                    tmp_graph[ny][nx] = graph_value


    def find_route():
        nonlocal shark_pos, sy, sx
        new_shark = []

        for i in range(4):
            ny, nx = sy + dy[i], sx + dx[i]
            shark_pos = []

            if 0 <= ny < 4 and 0 <= nx < 4:
                if graph[ny][nx]:
                    graph_value = graph[ny][nx]
                    graph[ny][nx] = []
                    dfs(ny, nx, [[len(graph_value), check_direction(dy[i], dx[i])]], deepcopy(graph))
                    graph[ny][nx] = graph_value
                else:
                    dfs(ny, nx, [[0, check_direction(dy[i], dx[i])]], deepcopy(graph))

                shark_pos.sort(key=lambda x: (-x[0], x[1]))
                new_shark += [shark_pos[0]]

        new_shark.sort(key=lambda x: (-x[0], x[1]))
        move_shark(new_shark[0][1])


    def check_direction(y, x):
        for i in range(4):
            if y == dy[i] and x == dx[i]:
                return i


    def move_shark(info):
        nonlocal sy, sx, graph, smells
        smells = []
        for d in info:
            sy, sx = sy + dy[d], sx + dx[d]
            if graph[sy][sx]:
                graph[sy][sx] = []
                smells += [[sy, sx]]


    def insert_smell():
        for y, x in smells:
            smell_graph[y][x] = -2


    def decrease_smell():
        for i in range(4):
            for j in range(4):
                if smell_graph[i][j] < 0:
                    smell_graph[i][j] += 1


    def reveal():
        for y, x, info in fish_pos:
            if not graph[y][x]:
                graph[y][x] = info
            else:
                graph[y][x] += info


    def count_fish():
        nonlocal answer
        for i in range(4):
            for j in range(4):
                if graph[i][j]:
                    answer += len(graph[i][j])


    for _ in range(S):
        replicate()
        move_fish()
        find_route()
        decrease_smell()
        insert_smell()
        reveal()

    count_fish()
    print(answer)

solution()