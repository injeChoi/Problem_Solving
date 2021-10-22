N = int(input())
nums = [int(input()) for _ in range(N)]
positive = [num for num in nums if num > 0]
negative = [num for num in nums if num < 0]
zero = nums.count(0)
answer = 0
positive.sort(reverse=True)
negative.sort()

if len(positive) > 0:
    i = 0
    while i < len(positive):
        if positive[i] == 1:
            answer += 1
        elif i+1 < len(positive) and positive[i+1] == 1:
            answer += positive[i] + positive[i+1]
            i += 1
        elif i+1 < len(positive) and positive[i+1] != 1:
            answer += positive[i] * positive[i+1]
            i += 1
        i += 1

    if len(positive) % 2 == 1 and positive[-1] != 1:
        answer += positive[-1]

if len(negative) > 0:
    if zero > 0 and len(negative) % 2 == 1:
        negative.pop()

    j = 0
    while j < len(negative):
        if j+1 >= len(negative):
            break
        answer += negative[j] * negative[j+1]
        j += 2

    if len(negative) % 2 == 1:
        answer += negative[-1]

print(answer)