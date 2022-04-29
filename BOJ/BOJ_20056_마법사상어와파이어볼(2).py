"""
https://www.acmicpc.net/problem/20056

문제 명세 중
'격자의 행과 열은 1번부터 N번까지 번호가 매겨져 있고, 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다'
이 부분을 잘못(?) 해석하는 바람에 시간을 한참 허비했다

내가 이해하기로는 행과 열이 원형 큐 처럼 이어져있는 거라면
횡, 종 움직임 뿐만 아니라 당연히 대각 움직임까지 원형 큐 처럼 움직일 줄 알았다

0000 다음과 같은 격자가 있을 때
0100 만약 1이 횡과 종으로 3칸 움직인다면
0000 당연히 1의 위치는 (1, 1)에서 횡 움직임 일 때: (1, 0), 종 움직임 일 때: (0, 1) 이 될 것이다
0000

여기서 문제는 나는 저 1이 좌측 하단 방향 대각으로 2칸 움직일 경우
0010 이렇게 격자가 될 것이라 생각하여 규칙을 찾으려고 노력했지만 규칙을 찾을 수 없었고
0000 이 과정에서 시간을 허비하게 됐다
0000
0000

하지만 대각 움직임이 이렇게 진행된다는 문제의 명세가 없었기 때문에
단순히 그냥 나머지 연산으로 대각 움직임을 구현했고 그 결과 격자의 움직임은 다음과 같았다
0000
0000
0000
0001
그리고 결론적으로 대각 움직임은 이렇게 움직이는게 맞았고 문제를 통과할 수 있었다
"""

def solution():
    dy = [-1, -1, 0, 1, 1, 1, 0, -1]
    dx = [0, 1, 1, 1, 0, -1, -1, -1]
    N, M, K = map(int, input().split())
    graph = [[[] for _ in range(N)] for _ in range(N)]
    answer = 0

    for _ in range(M):
        y, x, m, s, d = map(int, input().split())
        graph[y-1][x-1] += [[m, s, d]]


    def move_fireball():
        nonlocal graph
        tmp = [[[] for _ in range(N)] for _ in range(N)]

        for i in range(N):
            for j in range(N):
                if graph[i][j]:
                    for m, s, d in graph[i][j]:
                        y, x = (i + s * dy[d]) % N, (j + s * dx[d]) % N
                        tmp[y][x] += [[m, s, d]]

        graph = tmp


    def logic(i, j):
        mass = sum([info[0] for info in graph[i][j]]) // 5
        if mass == 0:
            graph[i][j] = []
            return
        speed = sum([info[1] for info in graph[i][j]]) // len(graph[i][j])
        directions = check_direction([info[2] for info in graph[i][j]])
        graph[i][j] = [[mass, speed, directions[i]] for i in range(4)]


    def check_direction(directions):
        if len(list(filter(lambda num: num % 2 == 0, directions))) == len(directions):
            return [0, 2, 4, 6]
        elif len(list(filter(lambda num: num % 2 == 1, directions))) == len(directions):
            return [0, 2, 4, 6]
        else:
            return [1, 3, 5, 7]


    def check_graph():
        for i in range(N):
            for j in range(N):
                if len(graph[i][j]) > 1:
                    logic(i, j)


    def calculate():
        nonlocal answer
        for i in range(N):
            for j in range(N):
                if graph[i][j]:
                    for m, s, d in graph[i][j]:
                        answer += m


    for _ in range(K):
        move_fireball()
        check_graph()

    calculate()
    print(answer)

solution()