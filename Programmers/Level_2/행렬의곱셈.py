'''
https://programmers.co.kr/learn/courses/30/lessons/12949

행렬 규칙을 까먹어서 좀 헤매게 된 문제
m * k, k * n 행렬이 있으면 
두 행렬을 곱했을 때 나오는 행렬은 m * n 형태이다.
그리고 행렬의 곱 연산을 하려면 무조건 k가 같은 수 이어야 한다.
고로, 결괏값이 들어갈 2차원 배열을 먼저 만들고
행렬의 성질을 이용한 곱 연산을 진행하여 최종 값을 만든다.
'''

def solution(arr1, arr2):
    answer = [[0] * len(arr2[0]) for _ in range(len(arr1))]

    for m in range(len(arr1)):
        for n in range(len(arr2[0])):
            for k in range(len(arr1[0])):
                answer[m][n] += arr1[m][k] * arr2[k][n]

    return answer
