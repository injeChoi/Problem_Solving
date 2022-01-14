'''
https://programmers.co.kr/learn/courses/30/lessons/43238

이분 탐색을 어떻게 활용할지 떠올리는게 가장 중요한 점

최소 심사 시간과 최대 심사 시간을 구한 후
이분 탐색을 시작한다. (line 17)

최소 심사 시간과 최대 심사 시간을 이분하여 mid 시간 값을 구한 후
mid 시간 안에 n 명을 심사할 수 있는지 없는지 판단한다. (line 22 ~ 27)

mid 시간 안에 n명을 심사할 수 없다면 mid를 증가 시킨다.
mid 시간 안에 n명을 심사할 수 있다면 mid를 감소 시킨다. (line 30 ~ 35)

최소 심사 시간과 최대 심사 시간이 같거나 최소 심사 시간이 더 커진 상황이 되면 
반복문을 종료하고 가장 최근에 찾은 답을 리턴한다. 
'''

def solution(n, times):
    answer = 0
    left, right = 1, max(times) * n

    while left <= right:
        mid = (left + right) // 2

        total = 0
        for time in times:
            total += mid // time

            if total >= n:
                break

        if total >= n:
            answer = mid
            right = mid - 1

        elif total < n:
            left = mid + 1

    return answer