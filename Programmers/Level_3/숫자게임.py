'''
https://programmers.co.kr/learn/courses/30/lessons/12987

투포인터 문제

배열 길이가 100,000 이기 때문에 단순 완전 탐색 O(N^2)으로는 시간 초과

배열 정렬 후 A와 B의 0번째 인덱스를 가리키는 포인터 지정
A[idx]와 B[idx]를 비교해서 B가 더 크면 답 1 증가
승패 여부 상관없이 B의 포인터는 계속 1씩 증가
A의 포인터는 B의 값이 더 클 때, 즉 B가 승점을 얻을 때만 증가

이러면 최악의 경우에도 A와 B를 비교하는 로직을 O(2N)의 시간복잡도로 계산 가능
'''

def solution(A, B):
    answer = 0
    aPoint = 0
    A.sort()
    B.sort()
 
    for b in B:
        if b > A[aPoint]:
            answer += 1
            aPoint += 1
    
    return answer

print(solution([1,2,4,12,16],[0,1,3,11,17]))