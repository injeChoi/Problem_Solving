'''
https://programmers.co.kr/learn/courses/30/lessons/87377

1. 두 직선의 교점 찾는 공식 활용
2. 평행일 때, 교점이 무수히 많을 때 예외처리 (divider)
3. 교점들의 y의 최대, 최솟값과 x의 최대, 최솟값 구하기
4. 이론적인 좌표와 컴퓨터적인 좌표 계산 후 별 찍기
'''

def solution(line):
    points = set()
    minX, minY, maxX, maxY = 10e16, 10e16, -10e16, -10e16
    width, height = 0, 0
    
    def findCrossPoint(l1, l2):
        nonlocal minX, minY, maxX, maxY       
        a1, b1, c1 = l1
        a2, b2, c2 = l2
        divider = (a1 * b2 - b1 * a2)
        
        if divider == 0:
            return
        
        x = (b1 * c2 - c1 * b2) / divider
        y = (c1 * a2 - a1 * c2) / divider

        if x.is_integer() and y.is_integer():
            points.add((int(y), int(x)))
            minX = min(minX, int(x))
            maxX = max(maxX, int(x))
            minY = min(minY, int(y))
            maxY = max(maxY, int(y))

    for i in range(len(line)):
        for j in range(i+1, len(line)):
            findCrossPoint(line[i], line[j])
    
    width = maxX - minX + 1
    height = maxY - minY + 1
    graph = [['.'] * width for _ in range(height)]
    
    for y, x in points:
        graph[maxY - y][x - minX] = '*'
    
    answer = [''.join(x) for x in graph]
    return answer

print(solution([[0, 1, -1], [1, 0, -1], [1, 0, 1]]))