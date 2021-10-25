N = int(input())
score = [int(input()) for _ in range(N)]
score.sort()
print(sum([abs(i-score[i-1]) for i in range(1, N+1)]))