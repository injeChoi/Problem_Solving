'''
https://www.acmicpc.net/problem/2573

재귀로 DFS를 하면 메모리초과 or 시간 초과
고로 이 문제도 스택을 활용해서 DFS 처리를 해야한다

녹일 얼음이 남아있는지 체크하고 얼음이 있다면 그룹 개수를 체크한다
그룹 개수가 2 이상이면 몇 번 녹였는지 리턴한다

그룹 개수가 2 미만이면 얼음을 '한 번에' 녹인다
한 번에 녹인다는 건 얼음 하나를 녹이고 나서 다음 얼음을 녹이는 것과 다르다
얼음을 하나씩 녹이면 n번째 녹이는 차례에 특정 얼음이 녹고 나서 얼음의 높이가 0이 되면
특정 얼음의 다음 차례에 있던 얼음이 녹는 양이 1 증가하게 되는 문제가 생긴다
고로 녹아야 할 얼음의 위치 정보와 녹는 양의 정보를 저장해두고 한 번에 녹인다
'''

def solution():
    N, M = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = [[0] * M for _ in range(N)]
    group_cnt = 0
    turn, flag = 0, 0
    
    def dfs(i, j):
        nonlocal visited 
        st = [[i, j]]
        visited[i][j] = 1
        
        while st:
            y, x = st.pop()

            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                
                if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] != 0 and not visited[ny][nx]:
                    visited[ny][nx] = 1
                    st += [[ny, nx]]
        
    
    def find_group():
        nonlocal group_cnt, visited
        
        group_cnt = 0
        visited = [[0] * M for _ in range(N)]
        
        for i in range(N):
            for j in range(M):
                if graph[i][j] != 0 and not visited[i][j]:
                    group_cnt += 1
                    dfs(i, j)
 
    
    def check_around(y, x):
        cnt = 0
        
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == 0:
                cnt += 1
                
        return cnt
    
    
    def melt():
        nonlocal graph
        should_melt = []
        
        for i in range(N):
            for j in range(M):
                if graph[i][j] != 0:
                    cnt = check_around(i, j)
                    should_melt += [[i, j, cnt]]
                    
        for i, j, cnt in should_melt:
            graph[i][j] -= cnt
            if graph[i][j] < 0:
                graph[i][j] = 0
    
    
    def find_ice():
        for i in range(N):
            for j in range(M):
                if graph[i][j] != 0:
                    return True
        return False
    
    
    while find_ice():
        find_group()
        
        if group_cnt >= 2:
            flag = True
            break
         
        turn += 1
        melt()
        
    
    if flag:
        print(turn)
    else:
        print(0)
    
    
solution()