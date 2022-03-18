'''
https://programmers.co.kr/learn/courses/30/lessons/12905

처음엔 2x2 사이즈 부터 시작해서 NxN 사이즈까지 정사각형 크기를 키워가며
board 전체를 순회하며 조사를 해야되나 싶었지만 
board의 최대 크기가 1000x1000인 것을 확인하고 위 방법은 철회했다

BFS로 풀어야하나 싶어서 로직을 아무리 고려해봐도 시간복잡도를 낮출 방법을 찾지 못했다
결국 BFS도 값이 1인 모든 board[i][j]에 대해 BFS 로직을 돌려야하기 때문...

1시간 반 넘게 고민해도 답이 안 나와서 결국 구글링을 했더니 역시나 DP 문제였다
DP 개념이 없으니 이런 문제만 나오면 나락 가버린다

풀이:
우선 2차원 배열 전체에서 1이 없는 경우를 대비해 예외처리

로직은 간단하다
board[row][col]에서 1을 발견하면 board[row-1][col-1], board[row-1][col], board[row][col-1]에서
최솟값을 찾아 1을 더한 값을 board[i][j]에 넣는다

각각의 board[row][col]은 현재 위치에서 가능한 최대 크기의 정사각형의 변의 길이를 나타내게 된다

만약 board[1][1]에서 바라봤을 때, board[0][0] = 0, board[1][0] = 1, board[0][1] = 1 인 상태라면
가능한 최대 크기는 1이다 (1 = 크기가 1x1인 정사각형) 
왜냐면 2x2 범위 안에 0이 있으니까

하지만 board[0][0] = 1, board[1][0] = 1, board[0][1] = 1 인 상태라면
board[0][0] = 1, board[1][0] = 1, board[0][1] = 1, board[1][1] = 1 이므로
가능한 최대 크기는 2가 된다 (크기가 2x2인 정사각형)
고로, board[1][1]에 현재 위치에서 최대 크기가 2가 될 수 있다고 저장해둔다

이렇게 쭉 가다가 board[9][9]가 1이어서 주위를 둘러보니
board[8][8] = 2, board[9][8] = 2, board[8][9] = 3
이라면 3개의 값 중 최솟값인 2에서 1을 더해 3을 board[9][9]에 넣어준다
그러면 board[9][9]위치에 봤을 때 3x3 크기의 정사각형을 만들 수 있다는 뜻이다

즉, 특정 위치의 값은 특정 위치에서 봤을 때 만들어질 수 있는 정사각형의 한 변의 길이를 나타낸다

하지만 이렇게 풀어도 시간복잡도에서 털렸는데 이유는 2차원 배열을 1차원 배열로 만들려고
사용한 sum(board, []) 함수 때문이다
내부적으로 어떻게 구현이 됐는지 모르겠지만 시간복잡도에서 좋지 못함을 알 수 있었기 때문에
새로운 board[row][col] 값을 구할 때 마다 기존 최댓값과 비교해서 더 큰 수를 찾아냈다
'''

def solution(board):
    answer = 0

    for row in board:
        if 1 in row:
            answer = 1
    
    if answer == 0:
        return 0
    
    for row in range(1, len(board)):
        for col in range(1, len(board[0])):
            if board[row][col] == 1:
                board[row][col] = min(board[row-1][col-1], board[row-1][col], board[row][col-1]) + 1
                answer = max(answer, board[row][col])
    
    return answer ** 2