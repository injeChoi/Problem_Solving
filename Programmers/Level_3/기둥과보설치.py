'''
https://programmers.co.kr/learn/courses/30/lessons/60061

설치, 삭제 구분없이 항상 저장된 모든 좌표를 순회하며 가능한 작업인지 검사한다
최악의 경우에도 100 * 100 * 1000 = 10,000,000이기 때문에 가능 

설치할 때 기준을 잘 세운다
설치 조건에 만족하면 설치한다 (set에 좌표 추가)

삭제는 일단 삭제하고 삭제한 녀석을 다시 설치하려 해본다
만약 다시 설치가 불가능하면 삭제 또한 불가능하다는 뜻이다
고로 삭제한 것을 원상복구 한다

좌표들을 정렬 후 리턴한다 
'''

def impossible(result):
    COL, ROW = 0, 1
    for x, y, a in result:
        if a == COL: 
            if y != 0 and (x, y-1, COL) not in result and \
        (x-1, y, ROW) not in result and (x, y, ROW) not in result:
                return True
        else: 
            if (x, y-1, COL) not in result and (x+1, y-1, COL) not in result and \
        not ((x-1, y, ROW) in result and (x+1, y, ROW) in result):
                return True
    return False

def solution(n, build_frame):
    result = set()
    
    for x, y, a, build in build_frame:
        item = (x, y, a)
        if build: 
            result.add(item)
            if impossible(result):
                result.remove(item)
        elif item in result:
            result.remove(item)
            if impossible(result):
                result.add(item)
                
    answer = map(list, result)
    return sorted(answer)

print(solution(5, [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]))