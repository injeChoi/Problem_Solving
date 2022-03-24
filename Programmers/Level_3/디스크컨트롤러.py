'''
https://programmers.co.kr/learn/courses/30/lessons/42627

풀이 방법
1. 요청 시간 기준 정렬
2. 가장 첫 번째 작업 시작
3. 작업이 끝나기 전에 새로운 요청이 있었는지 확인 -> line 21
3-1. 있었으면 그거 처리
3-1. 없으면 다음 요청까지 시간 더해가다가 다음 요청 시간 제일 작은거 처리
2~3번 반복  

total: 총 시간 
total - jobs[i][0]: 현재 작업을 요청한 시점부터 실제로 작업을 종료하기 까지 걸린 시간 -> 총 시간 - 요청 시간
answer: 현재 작업을 요청한 시점부터 실제로 작업을 종료하기 까지 걸린 시간들의 합 
'''

def solution(jobs):
    answer = 0
    total = 0
    l = len(jobs)
    jobs.sort(key = lambda x: x[1])

    while jobs:
        for i in range(len(jobs)):
            if jobs[i][0] <= total:
                total += jobs[i][1]
                answer += total - jobs[i][0]
                jobs.pop(i)
                break

        else: 
            total += 1
    
    return answer // l

print(solution([[0, 3], [1, 9], [2, 6]]))