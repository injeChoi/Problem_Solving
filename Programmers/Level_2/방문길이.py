def solution(dirs):
    u, d, l, r = (1, 0), (-1, 0), (0, -1), (0, 1)
    y = x = 0
    path = set()

    for direction in dirs:
        if direction == 'U':
            ny, nx = y + u[0], x + u[1]
        elif direction == 'D':
            ny, nx = y + d[0], x + d[1]
        elif direction == 'L':
            ny, nx = y + l[0], x + l[1]
        else:
            ny, nx = y + r[0], x + r[1]

        if -5 <= ny <= 5 and -5 <= nx <= 5:
            path.add((y, x, ny, nx))
            path.add((ny, nx, y, x))
            y, x = ny, nx

    return len(path) // 2

print(solution("LULLLLLLU"))
