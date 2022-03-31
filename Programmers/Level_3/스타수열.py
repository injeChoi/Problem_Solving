'''
https://programmers.co.kr/learn/courses/30/lessons/70130

간과한 점: 
수열을 무조건 n-1번째와 n번째가 붙은 상태로 자르는게 아닐 수도 있다
즉, n번째와 n+4번째가 하나의 뭉치로 될 수 있다

풀이:
a배열의 각 원소 개수를 센다
만약 특정 원소의 개수 * 2가 지금까지 구한 값 보다 작다면 최댓값이 될 수 없다는 뜻이니 건너뛴다

n과 n+1이 같으면 조건에 위배되고, 
특정 원소가 n과 n+1 둘 중 어느 것에도 해당하지 않는다면 공통 원소가 없어서 조건에 위배되니
인덱스를 1만 증가시키고 건너뛴다 (n+1, n+2가 조건에 부합하는지 체크해야하니까)

만약 조건에 위배되는 사항이 없다면 현재의 특정 원소로 구할 수 있는 부분 수열 길이를 2 증가시키고 인덱스도 2 증가시킨다
최종 부분 수열의 길이가 가장 큰 것을 리턴한다
'''

from collections import Counter

def solution(a):
    if len(a) < 2:
        return 0
    
    answer = 0
    counter = Counter(a)
    
    for key, value in counter.items():
        if value * 2 < answer:
            continue
        
        idx, l = 0, 0
        while idx < len(a)-1:
            if (key not in a[idx:idx+2]) or a[idx] == a[idx+1]:
                idx += 1
                continue
            
            idx, l = idx + 2, l + 2
            
        answer = max(answer, l)
        
    return answer
