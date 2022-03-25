'''
https://programmers.co.kr/learn/courses/30/lessons/49191

명제를 도출하기 까다로웠던 문제

그래프 문제라서 dfs, bfs로 양방향 성질을 따져서 답을 구하려 했지만
도무지 해법을 찾을 수 없어서 검색해서 풀었다

풀이 조건: 
A, B, C 라는 사람이 있을 때, 
1. A가 B보다 세고 B가 C보다 세면 A는 C보다 세다
2. A가 B보다 약하고 B가 C보다 약하면 A는 C보다 약하다

특정 인물에 A에 대해 A보다 센 사람과 약한 사람을 구분해서 저장한다
1번 사람부터 n번 사람까지 돌아가면서 본인보다 강한 사람, 약한 사람을 쭉 찾아서 정보를 update한다
본인보다 강한 사람 + 약한 사람의 수가 총원 - 1과 같으면 정확한 순위를 알 수 있는 사람이다
'''

from collections import defaultdict

def solution(n, results):
    answer = 0
    weakerThan, strongerThan = defaultdict(set), defaultdict(set)
    
    for winner, loser in results:
        weakerThan[winner].add(loser)
        strongerThan[loser].add(winner)
            
    for person in range(1, n+1):  
        # 조건 1. person보다 센 사람들은 person보다 약한 사람들보다 세다 
        for strongPerson in strongerThan[person]:
            weakerThan[strongPerson].update(weakerThan[person])

        # 조건 2. person보다 약한 사람들은 person보다 센 사람들 보다 약하다  
        for weakPerson in weakerThan[person]:
            strongerThan[weakPerson].update(strongerThan[person])

    for i in range(1, n+1):
        if len(weakerThan[i]) + len(strongerThan[i]) == n - 1:
            answer += 1
    
    return answer

print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))