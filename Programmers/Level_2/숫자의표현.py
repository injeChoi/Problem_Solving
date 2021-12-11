def solution(n):
    answer = 0
    i = 1

    while i <= n:
        total = 0

        if i + i+1 > n:
            break

        for j in range(i, n):
            if total == n:
                answer += 1
                break
            if total > n:
                break
            total += j

        i += 1

    return answer + 1

print(solution(15))
