'''
https://programmers.co.kr/learn/courses/30/lessons/42885

간단한 투 포인터 문제
배에 탑승할 수 있는 최대 인원은 2명 뿐인 것이 핵심이다

s번째와 e번째 사람을 동시에 태울 수 없다면 e번째 사람은 혼자 탑승해야 한다
고로, 혼자 타야하는 사람 카운팅을 따로 해야한다

포인터 두 개가 겹쳐지면 모든 경우에서 동시에 2명을 같이 태울 수 없는 조건이고
겹쳐지지 않으면, 2명을 같이 태우는 조건을 모두 완료하고 
중간 어딘가에 혼자 남아있는 s번째 사람만 배에 태울 수 있는 조건인 상황이다.
고로, 배를 하나 추가한다.
'''

def solution(people, limit):
    answer = remain = 0
    people.sort()
    s, e = 0, len(people) - 1

    while s < e:
        if people[s] + people[e] <= limit:
            answer += 1
            s, e = s + 1, e - 1
        else:
            e -= 1
            remain += 1

    if e - s >= 0:
        answer += 1
    
    return answer + remain
    