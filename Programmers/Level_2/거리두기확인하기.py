def solution(places):
    answer = []
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    def check(y, x, cy, cx):
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if [ny, nx] != [cy, cx]:
                if 0 <= ny < 5 and 0 <= nx < 5 and place[ny][nx] == 'P':
                    return 1
        return 0

    def problem(place):
        for y in range(5):
            for x in range(5):
                if place[y][x] == 'P':
                    for i in range(4):
                        ny, nx = y + dy[i], x + dx[i]
                        if 0 <= ny < 5 and 0 <= nx < 5:
                            if place[ny][nx] == 'O':
                                if check(ny, nx, y, x):
                                    answer.append(0)
                                    return 1

                            elif place[ny][nx] == 'P':
                                answer.append(0)
                                return 1
        return 0

    for place in places:
        if not problem(place):
            answer.append(1)

    print(answer)
    return answer

solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]])