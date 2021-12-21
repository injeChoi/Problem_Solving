'''
https://programmers.co.kr/learn/courses/30/lessons/87390

10^7 x 10^7의 시간 복잡도 때문에 규칙성을 찾는 것이 가장 중요한 포인트였다

n을 배열의 길이, left와 right 사이 범위의 값을 index 라고 할 때, (left, right는 1차원 배열 인덱스 범위)
index의 2차원 배열 행, 열 번호를 구하는 방법은 다음과 같다.

index // n = 행 번호, index % n = 열 번호
(행 번호와 열 번호 중 큰 값) + 1을 하면 2차원 배열의 값에 들어가있어야 할 값을 구할 수 있다.

ex) n = 4, left = 7, right = 14
    index의 범위는 7 ~ 14
    7 // 4 = 1, 7 % 4 = 3
    고로, max(1, 3) + 1 = 4
    2차원 배열의 1행 3열에는 4라는 값이 들어간다 

구한 값을 결과 리스트에 추가하면 답이 된다. 
'''

# 시간 초과 풀이 
# def solution(n, left, right):
#     arr = [[0] * n for _ in range(n)]
#     idx = 0

#     while idx < n:
#         for i in range(0, idx+1):
#             arr[i][idx] = idx + 1

#         for i in range(0, idx+1):
#             arr[idx][i] = idx + 1

#         idx += 1

#     return sum(arr, [])[left:right+1]

def solution(n, left, right):
    answer = []

    for i in range(left, right+1):
        answer.append(max(divmod(i, n)) + 1)

    return answer

print(solution(4, 7, 14))