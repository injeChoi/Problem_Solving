'''
https://programmers.co.kr/learn/courses/30/lessons/12913

0행 부터 n행 까지 단방향으로의 최댓값만 찾으면 되는줄 알고 한참 헤맨 문제
역방향으로 가도 최댓값이 되도록 하는 값을 찾는게 문제의 숨은 의도였다

전 단계를 previous, 현재 단계를 current라고 한다면,
previous에서 밟았던 열을 current에서 또 밟으면 안 되므로 해당 열을 idx로 두고
previous의 최댓값의 인덱스가 idx와 동일하다면 2번째로 큰 수,
다르다면 가장 큰 수를 current[idx] 값과 더해서 저장한다
그러면 current까지 최대한 크게 오는 값 들을 알 수 있다
'''


def solution(land):

    def selectMax(row, idx):
        if idx == row.index(max(row)):
            return sorted(row)[-2]
        else:
            return sorted(row)[-1]

    for row in range(1, len(land)):
        for idx in range(4):
            land[row][idx] += selectMax(land[row-1], idx)

    return max(land[-1])

# print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))