'''
https://programmers.co.kr/learn/courses/30/lessons/17679

먼저 2차원 배열을 회전 후 푼다. (바닥이 왼쪽이 되도록)
2 * 2 이상의 범위에 같은 문자들이 모여있으면 터져야한다.
터져야하는 위치를 shouldPop 리스트에 표기해둔다.
shouldPop에서 0으로 표기된 위치는 board에서 사라져야한다.
board[row]에서 해당 위치를 0으로 표기하고 while 문으로 0이 없어질 때 까지 remove를 한다.
remove한 개수만큼 borad[row] 뒤에 'X' 문자를 추가하여 빈공간임을 나타낸다.
shouldPop에 터져야할 원소가 없을 때 까지 반복한다. 
'''

def solution2(m, n, board):
    answer = 0
    board = [list(k[::-1]) for k in zip(*board)]

    def bfs(i, j, c):
        nonlocal shouldPop
        if board[i+1][j] == c and board[i][j+1] == c and board[i+1][j+1] == c:
            shouldPop[i][j], shouldPop[i+1][j], shouldPop[i][j+1], shouldPop[i+1][j+1] = 1, 1, 1, 1

    while True:
        shouldPop = [[0] * m for _ in range(n)]

        for i in range(n - 1):
            for j in range(m - 1):
                if board[i][j] != 'X':
                    bfs(i, j, board[i][j])
        
        popCount = sum(shouldPop, []).count(1)
        if popCount != 0:
            answer += popCount
        else:
            break

        for i in range(n):
            for j in range(m):
                if shouldPop[i][j] == 1:
                    board[i][j] = 0

        cnt = 0
        for row in range(n):
            while board[row].count(0) != 0:
                cnt += 1
                board[row].remove(0)
            board[row] += ['X'] * cnt

    return answer
