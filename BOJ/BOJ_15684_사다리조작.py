"""
https://www.acmicpc.net/problem/15684

브루트 포스 + DFS로 사다리를 놓을 수 있는 모든 위치를 찾아서 사다리를 놓아 보고
만약 그 상태에서 시작 위치랑 끝 위치가 동일하게 끝나면 정답이 될 수 있다

가장 고민을 많이 했던 부분은 사다리 배치를 어떻게 표현할까 였다
인접리스트로 표현하기 애매한 부분이 있다고 생각하여 2차원 배열로 표현하였다

중요한 포인트는 graph[i][j] = 1로 표현하는 것이 무슨 뜻이냐면
graph[i][j]와 graph[i][j+1]이 연결된 것이라고 여기는 것이다
이 부분이 중요한 이유는 i번 세로선의 결과가 i번이 나와야 한다는 점을 체크할 때 두드러진다

i번 세로선이 사다리를 타고 내려가다가 가로선을 만나서 우측 또는 좌측으로 이동 할 때
graph[i][pos]가 1로 표시돼있으면 graph[i][pos]과 graph[i][pos+1]이 연결된 것이니 우측으로,
graph[i][pos-1]가 1로 표시돼있으면 graph[i][pos-1]과 graph[i][pos]가 연결된 것이니 좌측으로 이동한다는 것을 염두 해야한다

새로운 가로선을 추가할 때 조건은 가로선이 연속하면 안 된다는 점이다
고로 가로선을 추가하려는 위치에서 좌측, 우측을 검사하여 가로선이 없다면 현 위치에 가로선을 추가하고 DFS를 새로 돌린다
이때 DFS를 돌리고나서 현 위치에 가로선을 추가하지 않고 다른 경우를 찾기 위해 가로선을 다시 지우는 것을 잊으면 안 된다

가지치기 조건은 만약 가로선을 놓게될 개수가 3 초과이거나 이미 구한 답 보다 같거나 크면 리턴하는 것이다
그리고 가로선을 놓을 수 있는 모든 경우를 탐색 할 때 중복으로 탐색하는 것을 방지하기 위해
y, x 값을 DFS 함수 인자로 넘겨서 y, x 다음 경우 부터 다시 탐색을 진행한다
이때 x 값은 y 값이 변경될 때 마다 1초 초기화해야 한다
y, x 값이 (3, 2)여서 다음 경우를 탐색한다 했을 때
y값이 증가하여 4가 되면 x는 2 부터가 아니라 1인 위치에서 부터 사다리를 놓아서 탐색해야 하기 때문이다
즉, y값이 증가하면 세로선 1-2 사이부터 가로선을 놓아야 하지 2-3 사이부터 가로선을 놓지 않는다는 뜻이다
"""

def solution():
    N, M, H = map(int, input().split())
    graph = [[0] * 11 for _ in range(31)]
    answer = 4

    for _ in range(M):
        a, b = map(int, input().split())
        graph[a][b] = 1

    def check():
        for idx in range(1, N+1):
            pos = idx
            for row in range(1, H+1):
                if graph[row][pos] == 1:
                    pos += 1
                elif graph[row][pos-1] == 1:
                    pos -= 1

            if pos != idx:
                return False

        return True

    def dfs(cnt, y, x):
        nonlocal answer
        if cnt >= answer:
            return

        if check():
            answer = cnt
            return

        for i in range(y, H+1):
            for j in range(x, N):
                if graph[i][j] == 0 and graph[i][j-1] == 0 and graph[i][j+1] == 0:
                    graph[i][j] = 1
                    dfs(cnt + 1, i, j)
                    graph[i][j] = 0
            x = 1

    dfs(0, 1, 1)

    if answer == 4:
        print(-1)
    else:
        print(answer)

solution()