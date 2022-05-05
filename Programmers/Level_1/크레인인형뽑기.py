'''
https://programmers.co.kr/learn/courses/30/lessons/64061

기본적인 스택 문제 + 2차원 배열 탐색 
'''

def solution(board, moves):
    answer = 0
    N = len(board)
    st = []
    
    for move in moves:
        for i in range(N):
            if board[i][move-1] != 0:
                if st and st[-1] == board[i][move-1]:
                    answer += 2
                    st.pop()
                else:
                    st.append(board[i][move-1])
                    
                board[i][move-1] = 0
                break
    
    return answer

print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]], [1,5,3,5,1,2,1,4]))