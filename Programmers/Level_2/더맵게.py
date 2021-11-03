import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)

    while scoville[0] < K:
        if len(scoville) == 2 and scoville[0] + scoville[1] * 2 < K:
            return -1

        f, s = heapq.heappop(scoville), heapq.heappop(scoville)
        answer += 1
        mixed = f + s * 2
        heapq.heappush(scoville, mixed)

    return answer