'''
https://programmers.co.kr/learn/courses/30/lessons/68646?language=python3

풀이:
특정 원소 idx 기준, 해당 원소의 좌측에 있는 숫자들을 A, 우측에 있는 숫자들을 B라고 할 때
idx가 A와 B 적어도 둘 중 하나의 최솟값 보다 작으면 idx는 안 터진다
Why? 
idx가 A의 최솟값 보다 커서 그냥 터질 수도 있지만,
idx가 A의 최솟값 보다 작고 B의 최솟값 보단 커서 1번의 찬스를 사용하고 본인보다 작은 것을 터트릴 수 있다
그러면 본인을 제외하곤 나머지 수들은 무조건 본인보다 큰 수임이 보장된다
그러면 idx 본인은 끝까지 생존 가능하다

시간 복잡도 향상:
2 포인터(?) 방식으로 좌측 끝과 우측 끝에서 반대 방향 끝까지 동시에 조사한다
최솟값이 갱신되는 경우가 있으면 답을 1 증가한다
만약 중복으로 답을 증가시킨 경우가 있으면 1 감소시키고 답 출력 
'''

def solution(a):
    answer = 2
    left, right = a[0], a[-1]
    
    for idx in range(1, len(a)-1):
        if a[idx] < left:
            answer += 1
            left = a[idx]
            
        if a[-1-idx] < right:
            answer += 1
            right = a[-1-idx]

    if left == right:
        answer -= 1
        
    return answer

print(solution([9, -1, -5]))