N, M = map(int, input().split())
ddeok = list(map(int, input().split()))
result = []

ddeok.sort()
# 초기 값 세팅 
left = 0
right = ddeok[-1]

def solution(arr, left, right):
    if left > right:
        return None

    total = 0
    cut = (left + right) // 2

    # 절단기 높이 보다 떡이 길면 남는 길이 합 구하기 
    for i in arr:
        if i > cut:
            total += i - cut

    # 남는 길이가 요구치 보다 크면 
    if total >= M:
        result.append(cut)
        solution(arr, cut+1, right)
    
    elif total < M:
        solution(arr, left, cut-1)

solution(ddeok, left, right)
result.sort()
print(result[-1])

    

