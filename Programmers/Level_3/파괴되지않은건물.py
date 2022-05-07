'''
https://programmers.co.kr/learn/courses/30/lessons/92344

정확성 통과, 효율성 실패
효율성을 맞추기 위해서는 누적합 (세그먼트 트리 등)을 사용해야 한다

적절히 2차원 배열을 슬라이싱 후 degree 만큼 추가, 감소 시킨 후 
최종 2차원 배열에서 0 초과인 원소의 개수를 세면 된다 
'''

def solution(board, skill):
    answer = 0
    
    def logic(tmp):
        for i in range(len(tmp)):
            for j in range(len(tmp[0])):
                if attack == 1:
                    tmp[i][j] -= degree
                else:
                    tmp[i][j] += degree
        
        idx = 0
        for i in range(sy, ey+1):
            board[i][sx:ex+1] = tmp[idx]
            idx += 1

    def calculate():
        total = 0
        for row in board:
            total += len(list(filter(lambda x: x > 0, row)))
        
        return total
    
    for attack, sy, sx, ey, ex, degree in skill:
        tmp = [board[row][sx:ex+1] for row in range(sy, ey+1)]
        logic(tmp)

    answer = calculate()
    return answer

print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]],
               [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))