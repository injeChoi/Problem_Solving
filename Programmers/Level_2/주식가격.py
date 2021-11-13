def solution(prices):
    answer = []

    for i in range(len(prices)):
        if i == len(prices)-1:
            answer.append(0)
        else:
            cnt = 1
            for j in range(i+1, len(prices)):
                if prices[i] > prices[j]:
                    answer.append(cnt)
                    break
                elif j == len(prices)-1:
                    answer.append(cnt)
                else:
                    cnt += 1

    return answer