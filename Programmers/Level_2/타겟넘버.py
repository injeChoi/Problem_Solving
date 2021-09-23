def solution(numbers, target):
    answer = 0
    length = len(numbers)

    def dfs(idx, result):
        if idx == length:
            if target == result:
                nonlocal answer 
                answer += 1
            return
        else: 
            dfs(idx+1, result+numbers[idx])
            dfs(idx+1, result-numbers[idx])

    dfs(0, 0)
    return answer

solution([1,1,1,1,1], 3)