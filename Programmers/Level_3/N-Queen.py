'''
https://programmers.co.kr/learn/courses/30/lessons/12952

전형적인 N-Queen 문제
행, 열, 대각 검사를 효율적으로 진행하기 위해 가지치기를 하는 것이 중요 
'''

def solution(n):
    board = [0] * n

    def dfs(n, row):
        ret = 0
        
        # 마지막 행 까지 겹친 부분이 없으면 1 증가 
        if n == row:
            return 1

        # 열 검사 
        for col in range(n):
            board[row] = col # row 행 col열에 퀸 놓았다 

            for y in range(row):
                # 가지치기, 행 열 대각 검사 
                if board[y] == board[row] or (abs(board[y] - board[row]) == (row - y)):
                    break
            else:
                ret += dfs(n ,row + 1)

        return ret

    return dfs(n, 0)

print(solution(4))